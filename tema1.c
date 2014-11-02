/* Calina Cristian-Florin , 313CA */
/* VARIANTA SIMPLA */
#define MAX 100
#include <stdio.h>
#include <math.h>
/* Functia distanta calculeaza distanta dintre 2 baloane
   Functia cond_ciocnire verifica conditia de ciocnire cu peretii
   Funcia stergere realizeaza stergerea baloanelor marcate
   Functia max calculeaza maximul dintre coordonatele peretilor
   Funcia min calculeaza minimul dintre coordonatele peretilor */
double distanta (double a1, double a2,double b1,double b2,double c1,double c2); 
double cond_ciocnire (double wx1, double wx2, double wy1, double wy2, double wz1,double wz2,double x,double y,double z,double r); 
void stergere (double a[MAX] ,double b[MAX], double c[MAX],double va[MAX],double vb[MAX],double vc[MAX],double r[MAX],int n,int k,unsigned int j[MAX]);
double max (double a, double b);
double min (double a, double b); 
int main()
{   /* Inputul */
    double wx1,wx2,wy1,wy2,wz1,wz2,x[MAX],y[MAX],z[MAX],r[MAX],vx[MAX],vy[MAX],vz[MAX];
    unsigned int tmax,t=0,i,j[MAX],sters=0,p,aux=0,n;                   
    scanf ("%lf %lf %lf %lf %lf %lf",&wx1,&wx2,&wy1,&wy2,&wz1,&wz2);   
    scanf ("%d",&tmax);                                              
    scanf ("%d",&n);                                                  
    for (i=1;i<=n;i++)                                               
    scanf ("%lf %lf %lf %lf %lf %lf %lf",&x[i],&y[i],&z[i],&r[i],&vx[i],&vy[i],&vz[i]);
    for (i=1;i<=n;i++)  // Initializarea elementelor vectorului de marcare cu 0
    {
         j[i]=0;
    }
    for (i=1;i<=n;i++)                          
    {   //Verificarea conditiei de ciocnire cu peretii+marcarea in caz afirmativ
        if (cond_ciocnire(wx1,wx2,wy1,wy2,wz1,wz2,x[i],y[i],z[i],r[i])==1)
        {
             j[i]=1;
        }  //In caz contrar, mai exista baloane in camera (aux=1)
        else aux=1;
    }               
    if (n>1)     //Daca sunt mai mult de 1 balon in camera se verifica ciocnirea
    {            //cu celelalte baloane.
        for (i=1;i<=n-1;i++)
        for (p=i+1;p<=n;p++)
        if (distanta(x[i],x[p],y[i],y[p],z[i],z[p])<=(r[i]+r[p]))
        {   //Daca distanta dintre centrele baloanelor este mai mica decat suma
            j[i]=1;     //razelor inseamna ca acestea se ciocnesc si le marchez
            j[p]=1;
        }  
    }
    i=1;
    while(i<=n)            
    {   
        if (j[i]==1) //Daca avem balon marcat => apelez functia stergere
        {            //si scad numarul de baloane ramase
            if (i<n) //i-ul nu va creste deoarece balonul se sterge si
            {        //valoarea lui i va reprezenta urmatorul balon
                 stergere (x,y,z,vx,vy,vz,r,n,i,j);
            }
            n--;
        }
        else    //in caz contrar verific urmatorul balon
        { 
            i++; 
        }
    }
    if (aux==1)  // Daca mai avem cel putin 1 balon in camera 
    {            //Afisez cate mai sunt si incepe simularea.
        printf("%d\n",n);
        while ((t<tmax)&&(aux==1))  //atat timp cat nu s-a ajuns la tmax              
        { 	                    //si mai sunt baloane in camera
            aux=0;    //aux=0 pentru ca nu se stie daca vor mai ramane sau nu           
            sters=0;  //variabila sters verifica daca s-au sters sau nu baloane 
            for (i=1;i<=n;i++)
            {   //cresc coordonatele baloanelor
                x[i]=x[i]+vx[i];                      
                y[i]=y[i]+vy[i];
                z[i]=z[i]+vz[i];
            }
            for (i=1;i<=n;i++)
            {   //verific cond de ciocnire cu peretii precum in testul initial
                if (cond_ciocnire(wx1,wx2,wy1,wy2,wz1,wz2,x[i],y[i],z[i],r[i])==1)
                {
                    j[i]=1;
                } 
                else aux=1;
            }
            if (n>1)
            {//verific cond de ciocnire intre baloane precum in testul initial
                for (i=1;i<=n-1;i++)
                for (p=i+1;p<=n;p++)
                if (distanta(x[i],x[p],y[i],y[p],z[i],z[p])<=r[i]+r[p])
                { 
                    j[i]=1;    
                    j[p]=1;
                }
            }                                                
            i=1;
            while(i<=n)                       
            {  //folosesc stergerea precum in testul initial+ dau valoarea 1 
                if (j[i]==1)  // lui sters in caz ca avem macar 1 balon sters
                { 
                     if (i<n)
                     {
                         stergere (x,y,z,vx,vy,vz,r,n,i,j);
                     }
                     n--;
                     sters=1;
                }
                else 
                            { 
                            i++; 
                        }
            }
            if ((sters==1)&&(aux==1)) //daca avem cel putin 1 balon sters si                                       
            {                         //mai sunt baloane in camera
                printf ("%d\n",t+1);  //afisez secunda urmatoare 
                printf ("%d\n",n);    //numarul de baloane ramase                                           
                for (i=1;i<=n;i++)   //si coordonatele acestora                                           
                printf ("%.1lf %.1lf %.1lf\n",x[i],y[i],z[i]);
            }  
            if (aux==0)   //in cazul in care nu mai sunt baloane in camera
            {             //si timpul nu a expirat
                printf("%d\n",t+1); //afisez secunda urmatoare.
            }
            t++;   //simularea se reapeleaza pentru urmatoarea secunda.                                                                   
         }
    }
    else   //in cazul in care inainte de simulare nu mai sunt baloane
    {      //in camera se afiseaza valoarea "0" precum in cerinta.
         printf("0\n");
    }
     return 0;
}
double max (double a, double b)
{ 
     return a>b?a:b;  //functia este apelata in cond_ciocnire
}
double min (double a, double  b)
{
     return a<b?a:b;  //functia este apelata in cond_ciocnire
}
double distanta (double a1,double a2,double b1,double b2,double c1,double c2)
{    //formula pentru distanta dintre doua puncte (centrele baloanelor)
     return sqrt(pow((a2-a1),2)+pow((b2-b1),2)+pow((c2-c1),2));        
}
void stergere (double a[MAX] ,double b[MAX], double c[MAX],double va[MAX],double vb[MAX],double vc[MAX],double r[MAX],int n,int k,unsigned int j[MAX])
{   //functia sterge prin atribuirea coordonatelor balonului urmator balonului
    int i;  //respectiv incepand de la pozitia k, in care balonul este marcat.
    for (i=k;i<=n-1;i++)  //Ultimul balon care va fi clona penultimului va fi 
    {                     //sters in main prin n--;
         a[i]=a[i+1];                  
         b[i]=b[i+1];
         c[i]=c[i+1];
         va[i]=va[i+1];
         vb[i]=vb[i+1];
         vc[i]=vc[i+1];
         r[i]=r[i+1];
         j[i]=j[i+1]; //balonul ii va memora si marcarea (0 sau 1) a 
    }                                         //balonului urmator.
}
double cond_ciocnire (double wx1, double wx2, double wy1, double wy2, double wz1,double wz2,double x,double y,double z,double r)
{//conditia de ciocnire se respecta daca coordonatele centrului balonului + raza este mai mica decat minimul sau mai mare decat maximul dintre pereti 
    if ((x-r)<=min(wx1,wx2)||(x+r)>=max(wx1,wx2)||(y-r)<=min(wy1,wy2)||(y+r)>=max(wy1,wy2)||(z-r)<=min(wz1,wz2)||(z+r)>=max(wz1,wz2))
    return 1;  //in caz ca balonul se ciocneste se va returna 1
    else return 0; //altfel se va returna 0
}
