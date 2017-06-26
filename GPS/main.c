//
//  main.c
//  GPS
//
//  Created by 20161104601 on 17/6/26.
//  Copyright © 2017年 20161104601. All rights reserved.
//



#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char time[10],gps,latitude1,longitude1,year[10],s[5],latitude[10],longitude[10];
    double v,course;
    FILE *fp2,*fp1,*fp3;
    char Time[10],Latitude1,Longitude1,moon[10],S[5],altitude[10];
    double Latitude,Longitude;
    int Gps;
    fp1=fopen("//Users//a20161104601//Desktop//GPS//gps1.txt","w+");
    fp2=fopen("//Users//a20161104601//Desktop//GPS//GPS170510.log","r");
    fp3=fopen("//Users//a20161104601//Desktop//GPS//gps.csv","w+");
    if(fp2==NULL)
    {
        printf("打开文件错误，要打开的文件可能不存在");
    }
    else
    {
        while(fscanf(fp2,"$GPRMC,%6s,%c,%8s,%c,%9s,%c,%lf,%lf,%6s,,%3s\n$GPGGA,%6s,%lf,%c,%lf,%c,%d,%2s,,%4s,M,,M,,%3s\n",time,&gps,latitude,&latitude1,longitude,&longitude1,&v,&course,year,s,Time,&Latitude,&Latitude1,&Longitude,&Longitude1,&Gps,moon,altitude,S)!=EOF)
        {
            if(gps=='A')
            {
                fprintf(fp1,"当前是%c%c年%c%c月%c%c日%c%c时%c%c分%c%c秒\n",year[4],year[5],year[2],year[3],year[0],year[1],time[0],time[1]+8,time[2],time[3],time[4],time[5]);
                printf("当前是%c%c年%c%c月%c%c日%c%c时%c%c分%c%c秒\n",year[4],year[5],year[2],year[3],year[0],year[1],time[0],time[1]+8,time[2],time[3],time[4],time[5]);
                fprintf(fp3,"%c%c年%c%c月%c%c日,%c%c时%c%c分%c%c秒,",year[4],year[5],year[2],year[3],year[0],year[1],time[0],time[1]+8,time[2],time[3],time[4],time[5]);
                if(latitude1=='N')
                {
                    fprintf(fp1,"该车位于北纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    printf("该车位于北纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    fprintf(fp3,"北纬%c%c度%c%c%c%c%c分,",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                }
                else
                {
                    fprintf(fp1,"该车位于南纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    printf("该车位于南纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    fprintf(fp3,"南纬%c%c度%c%c%c%c%c分,",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                }
                if(longitude1=='E')
                {
                    fprintf(fp1,"该车位于东经%c%c%c度%c%c%c%c分\n",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                    printf("该车位于东经%c%c%c度%c%c%c%c分\n",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                    fprintf(fp3,"东经%c%c%c度%c%c%c%c分,",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                }
                else
                {
                    fprintf(fp1,"该车位于西经%c%c%c度%c%c%c%c分\n",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                    printf("该车位于西经%c%c%c度%c%c%c%c分\n",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                    fprintf(fp3,"西经%c%c%c度%c%c%c%c分,",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                }
                fprintf(fp1,"地面速率是%lf节，地面航向是%lf度\n",v,course);
                printf("地面速率是%lf节，地面航向是%lf度\n",v,course);
                fprintf(fp3,"地面速率是%lf节,地面航向是%lf度,",v,course);
                
            }
            else
            {
                fprintf(fp1,"GPRMC无效定位\n");
                printf("GPRMC无效定位\n");
                fprintf(fp3,"GPRMC无效定位,");
            }
            fprintf(fp1,"GPS状态是：");
            printf("GPS状态是：");
            fprintf(fp3,"GPS状态是：,");
switch (Gps)
{
    case 0:
        fprintf(fp1,"初始化\n");
        printf("初始化\n");
        fprintf(fp3,"初始化,");
        break;
    case 1:
        fprintf(fp1,"单点定位\n");
        printf("单点定位\n");
        fprintf(fp3,"单点定位,");
        break;
    case 2:
        fprintf(fp1,"码差分\n");
        printf("码差分\n");
        fprintf(fp3,"码差分,");
        break;
    case 3:
        fprintf(fp1,"无效PPS\n");
        printf("无效PPS\n");
        fprintf(fp3,"无效PPS,");
        break;
    case 4:
        fprintf(fp1,"固定解\n");
        printf("固定解\n");
        fprintf(fp3,"固定解,");
        break;
    case 5:
        fprintf(fp1,"浮点解\n");
        printf("浮点解\n");
        fprintf(fp3,"浮点解,");
        break;
    case 6:
        fprintf(fp1,"正在估算\n");
        printf("正在估算\n");
        fprintf(fp3,"正在估算,");
        break;
    case 7:
        fprintf(fp1,"人工输入固定值\n");
        printf("人工输入固定值\n");
        fprintf(fp3,"人工输入固定值,");
        break;
    case 8:
        fprintf(fp1,"模拟模式\n");
        printf("模拟模式\n");
        fprintf(fp3,"模拟模式,");
        break;
    case 9:
        fprintf(fp1,"WAAS差分\n");
        printf("WAAS差分\n");
        fprintf(fp3,"WAAS差分,");
        break;
    default:
        break;
}
fprintf(fp1,"使用卫星数量:%s\n",moon);
fprintf(fp1,"海拔高度:%s\n",altitude);
printf("使用卫星数量:%s\n",moon);
printf("海拔高度:%s\n",altitude);
printf("\n");
fprintf(fp1,"\n");
fprintf(fp3,"使用卫星数量:%s,",moon);
fprintf(fp3,"海拔高度:%s,",altitude);
fprintf(fp3,"\n");


}

}


fclose(fp1);
fclose(fp2);
fclose(fp3);
}
