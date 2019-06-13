#ifndef SIMILARTHREAD_H
#define SIMILARTHREAD_H

#include <QObject>
#include <QThread>
#include "global.h"
#include <QMessageBox>
typedef struct complex1 //复数类型
{
    float real;       //实部
    float imag;       //虚部
}complex1;

class SimilarThread : public QThread
{
    Q_OBJECT
public:
    explicit SimilarThread(QThread *parent = nullptr);
    int No=0;
    int standard=0;
    float simResult=-1;
    void run();
private:

    ///////////////////////////////////////////
    void conjugate_complex1(int n,complex1 in[],complex1 out[]);
    void c_plus(complex1 a,complex1 b,complex1 *c);
    void c_mul(complex1 a,complex1 b,complex1 *c) ;
    void c_sub(complex1 a,complex1 b,complex1 *c);
    void c_div(complex1 a,complex1 b,complex1 *c);
    void x_corr(int N,complex1 f[]);
    double f_corr(int N,complex1 a[],complex1 b[]);
    void i_xcorr(int N,complex1 f[]);
    void c_abs(complex1 f[],float out[],int n);
    void Wn_i(int n,int i,complex1 *Wn,char flag);
    void kfft(float pr[],float pi[],float fr[],float fi[],int n,int k,int l,int il);
    double AudioComparison( int16_t a[], int16_t b[]);
    double AudioComparison_f( int16_t *a, int16_t *b);
    float Delaycalculate(int16_t a[], int16_t b[]);
    float Delaycalculate_2(int16_t a[], int16_t b[]);
    ////////////////////////////////////////////
signals:
    void sendSimilarity(int ch,float N);//发送相似度
    void workFinish();
public slots:
};

#endif // SIMILARTHREAD_H
