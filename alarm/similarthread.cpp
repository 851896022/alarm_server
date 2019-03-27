#include "similarthread.h"
//#define PI 3.14159265
#define PI 3.1415926535897932384626433832795
SimilarThread::SimilarThread(QThread *parent) : QThread(parent)
{

}
void SimilarThread::run()
{
    //qDebug()<<g->audioCache[No].count()<<g->audioCache[standard].count();
    qDebug()<<No<<"QThread ID"<<currentThreadId();
    if(g->audioCache[No].count()==65536*2)
    {
        if(g->audioCache[standard].count()==65536*2)
        {
            simResult=AudioComparison((short*)g->audioCache[No].data(),(short*)g->audioCache[standard].data());
            emit sendSimilarity(No/*通道*/,simResult);
            //simResult=tmp;
            //qDebug()<<No<<"work"<<QThread::currentThreadId()<<"sim="<<tmp;
        }
    }
    msleep(qrand()%200);
    emit workFinish();


}


//精度0.0001弧度
void SimilarThread::conjugate_complex1(int n,complex1 in[],complex1 out[])
{
    int i = 0;
    for(i=0;i<n;i++)
    {
        out[i].imag = -in[i].imag;
        out[i].real = in[i].real;
    }
}

void SimilarThread::c_abs(complex1 f[],float out[],int n)
{
    int i = 0;
    float t;
    for(i=0;i<n;i++)
    {
        t = f[i].real * f[i].real + f[i].imag * f[i].imag;
        out[i] = sqrt(t);
    }
}


void SimilarThread::c_plus(complex1 a,complex1 b,complex1 *c)
{
    c->real = a.real + b.real;
    c->imag = a.imag + b.imag;
}

void SimilarThread::c_sub(complex1 a,complex1 b,complex1 *c)
{
    c->real = a.real - b.real;
    c->imag = a.imag - b.imag;
}

void SimilarThread::c_mul(complex1 a,complex1 b,complex1 *c)
{
    c->real = a.real * b.real - a.imag * b.imag;
    c->imag = a.real * b.imag + a.imag * b.real;
}

void SimilarThread::c_div(complex1 a,complex1 b,complex1 *c)
{
    c->real = (a.real * b.real + a.imag * b.imag)/(b.real * b.real +b.imag * b.imag);
    c->imag = (a.imag * b.real - a.real * b.imag)/(b.real * b.real +b.imag * b.imag);
}

#define SWAP(a,b)  tempr=(a);(a)=(b);(b)=tempr

void SimilarThread::Wn_i(int n,int i,complex1 *Wn,char flag)
{
    Wn->real = cos(2*PI*i/n);
    if(flag == 1)
        Wn->imag = -sin(2*PI*i/n);
    else if(flag == 0)
        Wn->imag = -sin(2*PI*i/n);
}


void SimilarThread::x_corr(int N,complex1 f[])
{
    complex1 t={0,0};
    complex1 wn={0,0};
    int i=0,j=0,k=0,m=0,n=0,l=0,r=0,M=0;
    double p=2.0;
    int la=0,lb=0,lc=0;
    for(i=N,M=1;(i=i/2)!=1;M++);
    for(i=1,j=N/2;i<=N-2;i++)
    {
        if(i<j)
        {
            t=f[j];
            f[j]=f[i];
            f[i]=t;
        }
        k=N/2;
        while(k<=j)
        {
            j=j-k;
            k=k/2;
        }
        j=j+k;
    }

    for(m=1;m<=M;m++)
    {
        la=pow(p,m);
        lb=la/2;
        for(l=1;l<=lb;l++)
        {
            r=(l-1)*pow(p,M-m);
            for(n=l-1;n<N-1;n=n+la)
            {
                lc=n+lb;
                Wn_i(N,r,&wn,1);
                c_mul(f[lc],wn,&t);
                c_sub(f[n],t,&(f[lc]));
                c_plus(f[n],t,&(f[n]));
            }
        }
    }
}


void SimilarThread::i_xcorr(int N,complex1 f[])
{
    int i=0;
    conjugate_complex1(N,f,f);
    x_corr(N,f);
    conjugate_complex1(N,f,f);
    for(i=0;i<N;i++)
    {
        f[i].imag = (f[i].imag)/N;
        f[i].real = (f[i].real)/N;
    }
}


void SimilarThread::kfft(float pr[],float pi[],float fr[],float fi[],int n,int k,int l,int il)
{
    int it,m,is,i,j,nv,l0;
    float p,q,s,vr,vi,poddr,poddi;
    for (it=0; it<=n-1; it++)
    { m=it; is=0;
    for (i=0; i<=k-1; i++)
    { j=m/2; is=2*is+(m-2*j); m=j;}
    fr[it]=pr[is]; fi[it]=pi[is];
    }
    pr[0]=1.0; pi[0]=0.0;
    p=6.283185306/(1.0*n);
    pr[1]=cos(p); pi[1]=-sin(p);
    if (l!=0) pi[1]=-pi[1];
    for (i=2; i<=n-1; i++)
    { p=pr[i-1]*pr[1]; q=pi[i-1]*pi[1];
    s=(pr[i-1]+pi[i-1])*(pr[1]+pi[1]);
    pr[i]=p-q; pi[i]=s-p-q;
    }
    for (it=0; it<=n-2; it=it+2)
    { vr=fr[it]; vi=fi[it];
    fr[it]=vr+fr[it+1]; fi[it]=vi+fi[it+1];
    fr[it+1]=vr-fr[it+1]; fi[it+1]=vi-fi[it+1];
    }
    m=n/2; nv=2;
    for (l0=k-2; l0>=0; l0--)
    { m=m/2; nv=2*nv;
    for (it=0; it<=(m-1)*nv; it=it+nv)
        for (j=0; j<=(nv/2)-1; j++)
        { p=pr[m*j]*fr[it+j+nv/2];
    q=pi[m*j]*fi[it+j+nv/2];
    s=pr[m*j]+pi[m*j];
    s=s*(fr[it+j+nv/2]+fi[it+j+nv/2]);
    poddr=p-q; poddi=s-p-q;
    fr[it+j+nv/2]=fr[it+j]-poddr;
    fi[it+j+nv/2]=fi[it+j]-poddi;
    fr[it+j]=fr[it+j]+poddr;
    fi[it+j]=fi[it+j]+poddi;
    }
    }
    if (l!=0)
        for (i=0; i<=n-1; i++)
        { fr[i]=fr[i]/(1.0*n);
    fi[i]=fi[i]/(1.0*n);
    }
    if (il!=0)
        for (i=0; i<=n-1; i++)
        { pr[i]=sqrt(fr[i]*fr[i]+fi[i]*fi[i]);
    if (fabs(fr[i])<0.000001*fabs(fi[i]))
    { if ((fi[i]*fr[i])>0) pi[i]=90.0;
    else pi[i]=-90.0;
    }
    else
        pi[i]=atan(fi[i]/fr[i])*360.0/6.283185306;
    }
    return;
}


double SimilarThread::AudioComparison( int16_t *a, int16_t *b)
{


    int16_t buffera[65536];
    int16_t bufferb[65536];

    complex1 *bufferComp1=new complex1 [131072];
    complex1 *bufferComp2=new complex1 [131072];
    complex1 *bufferComp2Out=new complex1 [131072];
    complex1 *bufferCompMulOut=new complex1 [131072];
    complex1 bufferMulX,bufferMulY;
    double *bufferIfft=new double [131072];
    double sum1=0;
    double sum2=0;
    float MaxCoef = 0;
    double amplitude1=0;
    double amplitude2=0;
    double Rate = 0;
    //float MaxCoef;
    complex1 bufferMulTest;
    complex1 *buffferMulZ;
    //uint16_t FirstNum =65536;
    int i=0;
    float tp = 0;

    buffferMulZ=&bufferMulTest;

    amplitude1=0;
    amplitude2=0;
    sum1=0;
    sum2=0;
    memset(bufferComp1,0,sizeof(struct complex1)*131072);
    memset(bufferComp2,0,sizeof(struct complex1)*131072);
    for(i=0;i<65536;i++)
    {
        if(a[i]<100&&a[i]>-100)
        {
            buffera[i]=0;
        }
        else
        {
            buffera[i]=a[i];
        }
        if(b[i]<100 && b[i]>-100)
        {
            bufferb[i]=0;
        }
        else
        {
            bufferb[i]=b[i];
        }



    }

    for(i=0;i<65536;i++)
    {
        amplitude1=abs(buffera[i])+amplitude1;
        amplitude2=abs(bufferb[i])+amplitude2;
    }

    Rate=amplitude1/amplitude2;
    for(i=0;i<65536;i++)
    {
        bufferb[i]=bufferb[i]*Rate;
    }

    tp = 3.0518e-05;
    for(i=0;i<65536;i++)
    {
        bufferComp1[i].real=buffera[i]*tp;
        bufferComp2[i].real=bufferb[i]*tp;
    }
    //    kfft(bufferComp1.real,bufferComp1.imag,bufferComp1.real,bufferComp1.imag,131072,17,0,0);
    x_corr(131072, bufferComp1);
    x_corr(131072, bufferComp2);



    conjugate_complex1(131072,bufferComp2,bufferComp2Out);
    for(i=0;i<131072;i++)
    {
        bufferMulX.real= bufferComp1[i].real;
        bufferMulX.imag= bufferComp1[i].imag;
        bufferMulY.real= bufferComp2Out[i].real;
        bufferMulY.imag= bufferComp2Out[i].imag;
        c_mul(bufferMulX,bufferMulY, buffferMulZ) ;
        bufferCompMulOut[i].real=(*buffferMulZ).real;
        bufferCompMulOut[i].imag=(*buffferMulZ).imag;
    }
    //i_xcorr(131072,bufferCompMulOut);
    conjugate_complex1(131072,bufferCompMulOut,bufferCompMulOut);
    x_corr(131072,bufferCompMulOut);
    conjugate_complex1(131072,bufferCompMulOut,bufferCompMulOut);
    for(i=0;i<131072;i++)
    {
        bufferIfft[i]=bufferCompMulOut[i].real/65536;
    }
    for(i=0;i<65536;i++)
    {
        sum1=sum1+abs(buffera[i])*abs(buffera[i]);
        sum2=sum2+abs(bufferb[i])*abs(bufferb[i]);
    }
    sum1=sum1*sum2;
    sum1=sqrt(sum1)/32768/32768;
    sum1=1/sum1/2;
    for(i=0;i<131072;i++)
    {
        bufferIfft[i]=bufferIfft[i]*sum1;
    }
    MaxCoef=bufferIfft[0];
    for(i=0;i<131072;i++)
    {
        if(bufferIfft[i]<1)
        {
            if(MaxCoef<bufferIfft[i])
            {
                MaxCoef=bufferIfft[i];
            }
        }
    }
    if (MaxCoef<0||_isnan(MaxCoef))
    {
        MaxCoef = 0;
    }


    delete bufferComp1;
    delete bufferComp2;
    delete bufferComp2Out;
    delete bufferCompMulOut;
    delete bufferIfft;
    return  MaxCoef;

}
double SimilarThread::AudioComparison_f( short *a, short *b)
{

    for(int i=0;i<65536;i++)
    {
        if(a[i]<150&&a[i]>-150) a[i]=0;
        if(b[i]<150&&b[i]>-150) b[i]=0;
    }
    complex1 *ca=new complex1 [131072];
    if(!ca)QMessageBox::warning(NULL,"错误","new ca 失败");
    complex1 *cb=new complex1 [131072];
    if(!cb)QMessageBox::warning(NULL,"错误","new cb 失败");
    double comparison=0;
    int lvbo=10;
    memset(ca,0,sizeof(struct complex1)*131072);
    memset(cb,0,sizeof(struct complex1)*131072);
    for(int i=0;i<65536;i++)
    {
        if(a[i]<lvbo&&a[i]>0-lvbo)a[i]=0;
        if(b[i]<lvbo&&b[i]>0-lvbo)b[i]=0;
    }
    int counta=0;
    int countb=0;
    for(int i=0;i<65536;i++)
    {
        counta+=abs(a[i]);
        countb+=abs(b[i]);
    }
    double bizhi=(counta*1.0)/(countb*1.0);
    for(int i=0;i<65536;i++)
    {
        ca[i].real=a[i]/32768.0;
        cb[i].real=(b[i]*bizhi)/32768.0;
    }
    x_corr(131072, ca);
    x_corr(131072, cb);


    {
        QFile file(QString("A:/ftt")+QString::number(No)+QString(".csv"));
        if(file.open(QIODevice::WriteOnly))
        {
            QString data;
            for(int i=0;i<65536;i++)
            {
                data+=QString::number(a[i]);
                data+=",";
                data+=QString::number(b[i]);
                data+=",";
                data+=QString::number( ca[i].real);
                data+=",";
                data+=QString::number( ca[i].imag);
                data+=",";

                data+=QString::number( cb[i].real);
                data+=",";
                data+=QString::number( cb[i].imag);
                data+=",";
                data+=QString::number(sqrt(ca[i].real*ca[i].real+ca[i].imag*ca[i].imag));
                data+=",";
                data+=QString::number(sqrt(cb[i].real*cb[i].real+cb[i].imag*cb[i].imag));
                data+="\r\n";
            }
            file.write(data.toLatin1());
        }
    }
    comparison=f_corr(131072,ca,cb);
    if (comparison<0||_isnan(comparison))
    {
        comparison = 0;
    }
    delete[] ca;
    delete[] cb;
    return  comparison;
}

double SimilarThread::f_corr(int N, complex1 a[], complex1 b[])
{
    //====================================================
        double tA,tB,tC,P;
        tA=tB=tC=P=0;
        for(int i=0;i<N;i++)
        {

            double da=sqrt((a[i].imag)*(a[i].imag))+((a[i].real)*(a[i].real));
            double db=sqrt((b[i].imag)*(b[i].imag))+((b[i].real)*(b[i].real));
            tA+=da*db;//对x(t)*y(t)的积分
            tB+=da*da;//对x(t)*x(t)的积分
            tC+=db*db;//对y(t)*y(t)的积分
        }
        P=(tA/(sqrt(tB*tC)));
        if(P<0.0)P=0.0-P;

    //==========================
        return P;
}
