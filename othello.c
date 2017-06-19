//
//  othello.c
//  
//
//  Created by 山口航平 on 2017/01/29.
//
//aborttrap6 文字配列の上限を超えた。

#include "othello.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


int ue(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int xy=0;
    int tate1[7]={};
    
    int a[9][9]={};
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    
    if(3<=y&&y<=8){
        for(int j=1;j<=y-2;j++){
            for(int p=1;p<=j;p++){
                tate1[(j)]+=a[x][y-p]; //縦1
                if(tate1[j]==j&&b[x][y-j-1]==sengo&&b[x][y]==0){
                    
                    xy+=j;
                    
                }
            }
        }
    }
    return xy;
}

int sita(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int xy=0;
    int tate2[7]={};
    int a[9][9]={};
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(1<=y&&6>=y){
        for(int j=1;j<=7-y;j++){
            for(int p=1;p<=j;p++){
                tate2[j]+=a[x][y+p];  //縦2
                if(tate2[j]==j&&b[x][y+j+1]==sengo&&b[x][y]==0){
                    xy=j;
                    
                }
            }
        }
    }
    
    return xy;
}
int hidari(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int xy=0;
    int yoko1[7]={};
    int a[9][9]={};
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(x<=8&&x>=3){
        for(int j=1;j<=x-2;j++){
            for(int p=1;p<=j;p++){
                yoko1[(j)]+=a[x-p][y]; //横1
                if(yoko1[j]==j&&b[x-j-1][y]==sengo&&b[x][y]==0){
                    xy=j;
                }
            }
        }
    }
    return xy;
}
int migi(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int xy=0;
    int yoko2[7]={};
    int a[9][9]={};
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(x>=1&&x<=6){
        
        for(int j=1;j<=7-x;j++){
            for(int p=1;p<=j;p++){
                yoko2[j]+=a[x+p][y];  //横2
                if(yoko2[j]==j&&b[x+j+1][y]==sengo&&b[x][y]==0){
                    xy=j;
                }
                
            }
        }
    }
    return xy;
}

int hidariue(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int hidariue[7]={};//斜め左上
    int xy=0;
    int min1=(x-1<y-1)?x-1:y-1;
    int a[9][9]={};
    
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(min1<=7&&min1>=2){
        for(int j=1;j<=min1-1;j++){
            for(int p=1;p<=j;p++){
                hidariue[(j)]+=a[x-p][y-p]; //左上
                if(hidariue[j]==j&&b[x-j-1][y-j-1]==sengo&&b[x][y]==0){
                    xy=j;
                }
            }
        }
    }
    return xy;
}
int hidarisita(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int hidarisita[7]={};//斜め左下
    int xy=0;
    int min2=(x-1<8-y)?x-1:8-y;
    int a[9][9]={};
    
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(min2<=7&&min2>=2){
        for(int j=1;j<=min2-1;j++){
            for(int p=1;p<=j;p++){
                hidarisita[(j)]+=a[x-p][y+p]; //左下
                if(hidarisita[j]==j&&b[x-j-1][y+j+1]==sengo&&b[x][y]==0){
                    xy=j;
                }
            }
        }
    }
    return xy;
}
int migiue(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int migiue[7]={};//斜め右上
    int xy=0;
    int min2=(8-x<y-1)?8-x:y-1;
    int a[9][9]={};
    
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(min2<=7&&min2>=2){
        for(int j=1;j<=min2-1;j++){
            for(int p=1;p<=j;p++){
                migiue[(j)]+=a[x+p][y-p]; //右上
                if(migiue[j]==j&&b[x+j+1][y-j-1]==sengo&&b[x][y]==0){
                    xy=j;
                }
            }
        }
    }
    return xy;
}
int migisita(int b[9][9],int x,int y,int sengo){
    int teki;
    if(sengo==1){
        teki=-1;
    }else{
        teki=1;
    }
    int migisita[7]={};//斜め右上
    int xy=0;
    int min4=(8-x<8-y)?8-x:8-y;
    int a[9][9]={};
    
    for(int i=1;i<=8;i++){	//	敵の石があればそこを1とする。他は0とする。
        for(int j=1;j<=8;j++){
            if(b[i][j]==teki){
                a[i][j]=1 ;
            }else{
                a[i][j]=0;
            }
        }
        
    }
    if(min4<=7&&min4>=2){
        for(int j=1;j<=min4-1;j++){
            for(int p=1;p<=j;p++){
                migisita[(j)]+=a[x+p][y+p]; //右下
                if(migisita[j]==j&&b[x+j+1][y+j+1]==sengo&&b[x][y]==0){
                    xy=j;
                }
            }
        }
    }
    return xy;
}

void bannnohyouji(int a[9][9]){ //盤の様子が表示される。
    char *banmen[9][12]={"123456789"};
    int i=1;
    int j=1;
    
    for(i=0;i<=8;i++){
        for(j=0;j<=8;j++){
            if(a[i][j]==1){
                banmen[i][j]="●";
            }else if(a[i][j]==-1){
                banmen[i][j]="○";
            }else{
                banmen[i][j]=" ";
            }
        }
    }
    printf("%2d %d %d %d %d %d %d %d %d \n",0,1,2,3,4,5,6,7,8);
    for(int i=1;i<=8;i++){
        printf("%2d %s %s %s %s %s %s %s %s \n",i,banmen[1][i],banmen[2][i],banmen[3][i],banmen[4][i],banmen[5][i],banmen[6][i],banmen[7][i],banmen[8][i]);
    }
    
    
}


void bannnohyouji2(int a[9][9]){ //盤の様子が表示される。
    printf("%2d %2d %2d %2d %2d %2d %2d %2d %2d \n",0,1,2,3,4,5,6,7,8);
    for(int i=1;i<=8;i++){
        printf("%2d %2d %2d %2d %2d %2d %2d %2d %2d \n",i,a[1][i],a[2][i],a[3][i],a[4][i],a[5][i],a[6][i],a[7][i],a[8][i]);
    }
}

void kouhote3(int *kouho,int sengo,int a[9][9]){//現在の局面aに対して、候補を返す。
    int ban[9][9]={};
    //int a[9][9]={};
    int i=0;
    int j=0;
    
    
    for(int g=1;g<=8;g++){
        for(int h=1;h<=8;h++){
            if(ue(a,g,h,sengo)>=1){
                ban[g][h]+=1;
                
            }else{
                if(sita(a,g,h,sengo)>=1){
                    ban[g][h]+=1;
                    
                }else{
                    if(hidari(a,g,h,sengo)>=1){
                        ban[g][h]+=1;
                        
                    }else{
                        if(migi(a,g,h,sengo)>=1){
                            ban[g][h]+=1;
                            
                        }else{
                            if(hidariue(a,g,h,sengo)>=1){
                                ban[g][h]+=1;
                                
                            }else{
                                if(hidarisita(a,g,h,sengo)>=1){
                                    ban[g][h]+=1;
                                    
                                }else{
                                    if(migiue(a,g,h,sengo)>=1){
                                        ban[g][h]+=1;
                                        
                                    }else{
                                        if(migisita(a,g,h,sengo)>=1){
                                            ban[g][h]+=1;
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<=8;i++){//aに現在の局面を入れた。
        for(j=0;j<=8;j++){
            *kouho=ban[i][j];
            kouho++;
        }
    }
    
    
}



void hikkurikaesu2(int *ban,int x,int y,int sengo){//x,yは合法手のみ。*banは現在の局面の配列の先頭要素の番地
    
    int ban3[9][9]={};
    int i=0;
    int j=0;
    int *start=ban;//アドレス番地の初期値を記録しておく。
    
    for(i=0;i<=8;i++){
        for(j=0;j<=8;j++){
            ban3[i][j]=*ban;
            ban++;
        }
    }
    
    int b1=ue(ban3,x,y,sengo);//現在の局面ban2を渡し、上にひっくり返すことができる石の数を返す関数。
    int b2=sita(ban3,x,y,sengo);
    int b3=hidari(ban3,x,y,sengo);
    int b4=migi(ban3,x,y,sengo);
    int b5=hidariue(ban3,x,y,sengo);
    int b6=hidarisita(ban3,x,y,sengo);
    int b7=migiue(ban3,x,y,sengo);
    int b8=migisita(ban3,x,y,sengo);
    
    
    if(b1!=0){
        for(int j1=1;j1<=b1;j1++){//(x,y)に対して可能な候補手ならばひっくり返す。
            ban3[x][y-j1]=sengo;	//ue(ban2,x,y)とは、ban2における(x,y)とひっくり返す相手の石の個数
        }
    }
    
    if(b2!=0){
        for(int j2=1;j2<=b2;j2++){
            ban3[x][y+j2]=sengo;
        }
    }
    
    if(b3!=0){
        for(int j3=1;j3<=b3;j3++){
            ban3[x-j3][y]=sengo;
        }
    }
    
    if(b4!=0){
        for(int j4=1;j4<=b4;j4++){
            ban3[x+j4][y]=sengo;
        }
    }
    
    if(b5!=0){
        for(int j5=1;j5<=b5;j5++){
            ban3[x-j5][y-j5]=sengo;
        }
    }
    
    if(b6!=0){
        for(int j6=1;j6<=b6;j6++){
            ban3[x-j6][y+j6]=sengo;
        }
    }
    
    if(b7!=0){
        for(int j7=1;j7<=b7;j7++){
            ban3[x+j7][y-j7]=sengo;
        }
    }
    
    if(b8!=0){
        for(int j8=1;j8<=b8;j8++){
            ban3[x+j8][y+j8]=sengo;
        }
    }
    
    ban3[x][y]=sengo;//打ったところに自分の石を置く
    
    ban=start;
    for(i=0;i<=8;i++){//ban3の情報を*banアドレスにアクセスして上書きする。
        for(j=0;j<=8;j++){
            *ban=ban3[i][j];
            ban++;
        }
    }
    

}

int getrandom(int max){//最大値がmaxの乱数を返す。
    //srand((unsigned)time( NULL ));
    
    //int k=1+(int)(rand()*(max)/RAND_MAX);
    int k=1+rand()%(max);
    //printf("rand()=%dRAND_MAX=%d",rand(),RAND_MAX);
    //printf("result=%d¥n",k);
    return k;
}

void randomm(int *a,int sengo,int now[9][9],int te){//局面aにおいてランダムな手を返す。
    int ban[9][9]={};//ひっくり返した局面。
    int k=te;//候補手の数
    int b[9][9]={};//候補手を入れる配列。
    kouhote3(&b[0][0],sengo,now);
    //printf("randomm, kouhote");
    //bannnohyouji2(b);//////////////////////
    
    int i=0;
    int j=0;
    /*for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(b[i][j]==1){
                k+=1;
            }
        }
    }*/
    //printf("k=%d\n",k);
    int p;
    if(k==1){
        p=1;
    }else{
        p=getrandom(k);
    }
    //printf("k=%dp=%d",k,p);
    
    int k1=1;
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(b[i][j]==1){
                if(k1==p){
                    hikkurikaesu2(a,i,j,sengo);//ここで元のaがひっくり返っている。
                    //bannnohyouji(now);
                }
                k1+=1;
            }
        }
    }
    
}
int tesuu(int a[9][9],int sengo){
    int tesu=0;
    int b[9][9]={};
    kouhote3(&b[0][0],sengo,a);
    
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(b[i][j]==1){
                tesu+=1;
            }
        }
    }
    return tesu;
}

bool hantei(int b[9][9],int sengo){
    bool hantei=false;
    if(tesuu(b,sengo)>=1){
        hantei=true;
    }else{
        //printf("a");
        hantei=false;
    }
    return hantei;
}

int b(int ban[9][9],int sengo){//与えられた盤面からランダムに着手し、勝ったら1を返すメソッド。
    
    int kati=0;
    int pass=0;
    int banmen[9][9]={};
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            banmen[i][j]=ban[i][j];
        }
    }
    
    int sengoaite=sengo*(-1);
    
    int tesu=0;
    
    while(true){
        tesu=tesuu(banmen,sengo);
        if(tesu>=1){
            randomm(&banmen[0][0],sengo,banmen,tesu);
            //bannnohyouji(banmen);
            pass=0;
        }else{
            pass+=1;
            if(pass==2){
                //saisyuukyokumen=ban;
                //printf("a");
                //bannnohyouji(banmen);
                break;
            }
        }
        tesu=tesuu(banmen,sengoaite);
        if(tesu>=1){
            randomm(&banmen[0][0],sengoaite,banmen,tesu);
            //bannnohyouji(banmen);
            pass=0;
        }else{
            pass+=1;
            if(pass==2){
                //saisyuukyokumen=ban;
                
                //bannnohyouji(banmen);
                break;
            }
        }
    }
    //printf("b\n");
    //bannnohyouji(banmen);
    int x=0;
    int y=0;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(banmen[i][j]==sengo){
                x+=1;
            }else if(banmen[i][j]==sengoaite){
                y+=1;
            }
        }
    }
    //bannnohyouji2(ban);
    
    if(x<=y){
        kati=1;
    }
    
    return kati;
}

void saizen(int *ba,int sengo,int ban[9][9]){//与えられた局面における最善手を返す。*b=~~~として、ポインタにアクセスして変更させる。
    int p=0;//勝ち数。
    int saizente[9][9]={};
    int kouho[9][9]={};
    int i=0;
    int j=0;
    int i1=0;
    int j1=0;
    int aite=sengo*(-1);
    int now[9][9]={};//現在の局面。自由に動かしていく。
    for(i=0;i<=8;i++){
        for(j=0;j<=8;j++){
            now[i][j]=ban[i][j];
        }
    }
    kouhote3(&kouho[0][0],sengo,ban);
    //bannnohyouji2(now);
    
    int x=0;//候補手
    int y=0;
    
    //kouhote3(*kouho,sengo,ban)[i][j]==1;//kouhoのポインタを渡して、それを変更させる。現在の局面banを渡す。
    
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(kouho[i][j]==1){
                int katisuu=0;
                hikkurikaesu2(&now[0][0],i,j,sengo);//候補に対して一手進めた
                for(int k=1;k<=150;k++){//25回戦わせている。
                    //printf("saizen k=%d\n",k);
                    katisuu+=b(now,aite);//b1では、局面を変えることはなく、勝敗のみを返す。
                    //printf("saizen k=%d\n",k);
                }
                if(p<=katisuu){
                    x=i;
                    y=j;
                    p=katisuu;
                    //printf("katisuu=%d",p);
                }
                for(i1=0;i1<=8;i1++){//nowを戻す。
                    for(j1=0;j1<=8;j1++){
                        now[i1][j1]=ban[i1][j1];
                    }
                }
            }
            
        }
    }
    //printf("%d/150 %d\n",p,sengo);
    hikkurikaesu2(&ban[0][0],x,y,sengo);
    for(i=0;i<=8;i++){
        for(j=0;j<=8;j++){
            *ba=ban[i][j];
            ba++;
        }
    }
}

void syouhai(int ban[9][9]){
    int sen=0;
    int go=0;
    int i=0;
    int j=0;
    
    for(i=0;i<=8;i++){
        for(j=0;j<=8;j++){
            if(ban[i][j]==1){
                sen++;
            }else if(ban[i][j]==-1){
                go++;
            }
        }
    }
    if(sen>go){
        printf("%d対%dで先手の勝ち",sen,go);
    }else if(sen<go){
        printf("%d対%dで後手の勝ち",sen,go);
    }else{
        printf("%d対%dで引分",sen,sen);
    }
    
}

void a1(){
    //Ai a=new Ai();
    int ban[9][9]={};
    ban[4][4]=-1;//インスタンスが共有する盤面の初期配置
    ban[4][5]=1;
    ban[5][4]=1;
    ban[5][5]=-1;
    int kouho[9][9]={};
    int a=0;
    int b=0;
    
    int pass=0;
    
    bannnohyouji(ban);
    
    while(true){
        if(hantei(ban,1)==true){
            //saizen(ban,1);
            kouhote3(&kouho[0][0],1,ban);
            a=0;
            scanf("%d",&a);
            b=0;
            scanf("%d",&b);
            while(kouho[a][b]==0){
                printf("もう一度入力してください。");
                a=0;
                scanf("%d",&a);
                b=0;
                scanf("%d",&b);
            }
            hikkurikaesu2(&ban[0][0],a,b,1);
            //saizen(&ban[0][0],1,ban);
            bannnohyouji(ban);
            pass=0;
        }else{
            printf("pass");
            pass+=1;
            if(pass==2){
                //katimake(ban);
                break;
            }
        }
        if(hantei(ban,-1)==true){
            saizen(&ban[0][0],-1,ban);
            bannnohyouji(ban);
            pass=0;
        }else{
            printf("pass");
            pass+=1;
            if(pass==2){
                //katimake(ban);
                break;
            }
        }
    }
    syouhai(ban);
}




int main(){
    srand(time(NULL));//現在の時刻を取得。実行ごとに出力される乱数を変更するため。
    
    
    int ban[9][9]={};

    
    ban[4][4]=1;
    ban[4][5]=-1;

    ban[5][4]=-1;
    ban[5][5]=1;


    a1();
    
    return 0;
}



