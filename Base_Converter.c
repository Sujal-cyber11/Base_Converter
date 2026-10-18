#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char base[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
double power(int number, int exp);
void OTD(char *num , char *frac, int SB,int RB);
void DTO(double num,int RB);

int main(){
    int SB;
    int RB;
    printf("----------MENU---------\n");
    printf("Enter Source Base :");
    scanf("%d", &SB);
    int SBc;
    while((SBc=getchar())!='\n' && SBc!=EOF);
    printf("Enter Result Base :");
    scanf("%d", &RB);
    int RBc;
    while((RBc=getchar())!='\n' && RBc!=EOF);
    if(SB==10){
        double num=0;
        printf("Enter The Number :");
        scanf("%lf", &num);
        DTO(num,RB);

    }else{


        char num[1024]="";
        printf("Enter The Number :");
        fgets(num,sizeof(num),stdin);
        num[strcspn(num,"\n")]='\0';
        char *number = num;
        char *point=strchr(num,'.');
        if(point == NULL){
            char *whole=malloc((strlen(num)+1)*sizeof(char));
            char *fraction=malloc(2*sizeof(char));
            fraction[0]='0';
            fraction[1]='\0';
            strcpy(whole,num);
            OTD(whole,fraction,SB,RB);
            free(fraction);
            free(whole);
            fraction=NULL;
            whole=NULL;
        }
        else{
            int diff= point-number;
            char *fract = strchr(num,'\0');
            int fraction= fract-point-1;
            char *pwhole=malloc((diff+1) * sizeof(char));
            char *pfraction=malloc((fraction+1)*sizeof(char));
            for(int dig = 0 ; dig < diff ; dig++){
                pwhole[dig] = num[dig];
            }
            for(int frac = diff+1; frac<=fraction+diff; frac++){
                pfraction[frac-diff-1] = num[frac];
            }
            pwhole[diff]='\0';
            pfraction[fraction]='\0';
            printf("\n");
            
            OTD(pwhole,pfraction,SB,RB);

            free(pwhole);
            free(pfraction);
            pwhole=NULL;
            pfraction=NULL;
        }
    }
    return 0;


}
double power(int number,int exp){
    double Acc=1;
    while(exp !=0){
        if(exp%2==0){
            number *= number;
            exp=exp/2;

        }
        else{
            Acc*=number;
            number*=number;
            exp=exp/2;
        }
    }
    return Acc;
}
void OTD(char *num , char *frac, int SB,int RB){
    //Whole Number
    int w[1024]={};
    double f[20]={};
    long long int number=0;
    double fraction=0;
    for(int seeker=0;seeker<strlen(num);seeker++){
        w[seeker]=(strchr(base,num[seeker])-strchr(base,'0')) * power(SB,strlen(num)-seeker-1);
        number+=w[seeker];
    }
    //Fractional Number
    for(int seeker=1;seeker<=strlen(frac);seeker++){
        f[seeker-1]=(double)(strchr(base,frac[seeker-1])-strchr(base,'0')) * (double)1/(power(SB,seeker));
        fraction+=f[seeker-1];

    }
    double result = number + fraction ;
    if(RB==10){
        printf("Answer-----%.10lg",result);
    }
    else{
        DTO(result,RB);
    }


}
void DTO(double num,int OB){
    int search;
    char tempw[100]="";
    char w[100]="";
    char f[100]="";
    int whole = num;
    double frac = num-whole;
    int chr;
    int count = 0;
    // Whole part
    while(whole>0){
        search = whole % OB;
        tempw[count]=base[search];
        whole/=OB;
        count++;
    }
    for(int sort=0;sort<count;sort++){
        w[sort]=tempw[count-1-sort];

    }
    w[count]='\0';
    for(int fract=0;fract<10;fract++){

        frac*=OB;
        chr=(int)frac;
        f[fract]=base[chr];
        frac=frac-chr;

    }
    printf("Answer-----%s.%s", w , f);


}