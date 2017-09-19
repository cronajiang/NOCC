#include <cmath>
#include <string>
#include <windows.h>
#include <QDebug>
#include "..\NOCC-PRIVATE\AotfLibrary.h"
#include "borlfianium.h"

using namespace std;

BORLFianium::BORLFianium()
{

}

void BORLFianium::BORLFianiumFunctn(int iFunct)
{
 iFunctn=iFunct;
}

void BORLFianium::BORLFianiumChannel(int iCh)
{
 iChannel=iCh;
}

void BORLFianium::BORLFianiumWavelength(int iWv)
{
 iWavelength=iWv;
}


void BORLFianium::BORLFianiumPower(float fPow)
{
 fPowerlevel=fPow;
}

void BORLFianium::BORLFianiumConnect()
{
    int iInstance = 0;
    HANDLE hAotfController = AotfOpen(iInstance);

        if (hAotfController)
        {
 //     printf("AotfController-%d successfully opened.\n", iInstance);

            int iReturnediInstance = AotfGetInstance(hAotfController); // printf("AotfController connected at Instance %d\n", iReturnediInstance);

            if (!AotfClose(hAotfController))
            FeedbackCodes=-2; //                printf("AotfClose failed.\n");

            FeedbackCodes=iReturnediInstance;
        }
    else
            FeedbackCodes=-1; //       printf("AotfController-%d could not be opened.\n", iInstance);


}


void BORLFianium::BORLFianiumPowerScale()
{
    if((fPowerlevel<=100)&&(fPowerlevel>=0))
    {
        fPowerlevel = fPowerlevel/100*16383;  //Laser Power Module of 14-bit
        iPowerlevel = ceil(fPowerlevel);
    }
    else
    {
       FeedbackCodes=-3;// printf("BORL AOTF WARNING: Crystal power must be between 0 and 100\n");
       iPowerlevel = 0;
    }
}


void BORLFianium::BORLFianiumWlngtScale()
{
    if((iWavelength>=600)&&(iWavelength<=900))
    {
//        fWavelength = -1.73732517482515e-07*pow(iWavelength,3)+0.000578715034965027*pow(iWavelength,2)-0.688722465034958*pow(iWavelength,1)+342.115192307690; //
//
//        fWavelength = -1.26331238521227e-101*pow(iWavelength,39)+2.14351871440615e-97*pow(iWavelength,38)-1.13473956032315e-93*pow(iWavelength,37)+3.08831078780217e-90*pow(iWavelength,36)-5.44594434010593e-87*pow(iWavelength,35)+7.63262073775047e-84*pow(iWavelength,34)-9.17405262901409e-81*pow(iWavelength,33)+7.46874239686178e-78*pow(iWavelength,32)-1.10980395636865e-75*pow(iWavelength,31)-4.42001756022261e-72*pow(iWavelength,30)+3.35247146629403e-69*pow(iWavelength,29)+1.14412975445918e-66*pow(iWavelength,28)-2.93192114932224e-63*pow(iWavelength,27)+1.53827703337009e-60*pow(iWavelength,26)+1.86016411992028e-58*pow(iWavelength,25)-5.79234069576266e-55*pow(iWavelength,24)-7.39857258452607e-54*pow(iWavelength,23)+2.68192022590277e-49*pow(iWavelength,22)+5.85037870642950e-48*pow(iWavelength,21)-1.17514161333866e-44*pow(iWavelength,20)-2.26057867790055e-40*pow(iWavelength,19)+1.96143839426122e-37*pow(iWavelength,18)-1.24185757736393e-35*pow(iWavelength,17)-4.75443285045262e-32*pow(iWavelength,16)+2.13386592419911e-29*pow(iWavelength,15)+2.81720248981319e-27*pow(iWavelength,14)-1.55167066839957e-23*pow(iWavelength,13)+1.74890622414670e-20*pow(iWavelength,12)-1.17526912503689e-17*pow(iWavelength,11)+5.14923875862892e-15*pow(iWavelength,10)-1.07839123922133e-12*pow(iWavelength,9)+2.61515739334910e-10*pow(iWavelength,8)-7.50761095116304e-07*pow(iWavelength,7)+0.000586800531469264*pow(iWavelength,6)-0.0865436886694557*pow(iWavelength,5)-72.7128020951017*pow(iWavelength,4)+22942.9887135691*pow(iWavelength,3)+6008095.45890205*pow(iWavelength,2)-3630895951.13582*pow(iWavelength,1)+456643251541.720;

        for(int i=0;i<378*2;i=2+i)
        {
            if((iWavelength<=FreqTable[i])&&(iWavelength>FreqTable[i+2]))
            {
                fWavelength=(FreqTable[i+1]+FreqTable[i+3])/(FreqTable[i]+FreqTable[i+2])*iWavelength;
            }
        }

//        printf("%f \n",fWavelength);
//        return fWavelength;
    }
    else
    {
//       printf("BORL AOTF WARNING: WAVELENGHT must be between 600 and 1000\n");
        FeedbackCodes=-4; //WAVELENGHT must be between 600 and 1000
    }
}


void BORLFianium::BORLFianiumSetWavelenght()
{
    int iInstance = 0;
    string StrComand="dds f " + to_string(iChannel) + " " + to_string(fWavelength) + "\r";
    char cCommand[30];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    printf(cCommand);
    printf("\n");
        HANDLE hAotfController = AotfOpen(iInstance);

        if (hAotfController)
        {
            if (!AotfWrite(hAotfController, strlen(cCommand), cCommand))
               FeedbackCodes=-5; // printf("AotfWrite failed.\n");

            if (!AotfClose(hAotfController))
               FeedbackCodes=-2; //printf("AotfClose failed.\n");
         }
        else
             FeedbackCodes=-1;//printf("AotfController-%d could not be opened.\n", iInstance);
}


void BORLFianium::BORLFianiumSetPower()
{
    int iInstance = 0;
    string StrComand="dds a " + to_string(iChannel) + " " + to_string(iPowerlevel) + "\r";
    char cCommand[30];
    strncpy(cCommand,StrComand.c_str(),sizeof(cCommand));
    cCommand[sizeof(cCommand)-1]=0;
    printf(cCommand);
    printf("\n");
        HANDLE hAotfController = AotfOpen(iInstance);

        if (hAotfController)
        {
            if (!AotfWrite(hAotfController, strlen(cCommand), cCommand))
               FeedbackCodes=-6; // printf("AotfWrite failed.\n");

            if (!AotfClose(hAotfController))
               FeedbackCodes=-2; //printf("AotfClose failed.\n");
         }
        else
             FeedbackCodes=-1;//printf("AotfController-%d could not be opened.\n", iInstance);
}


void BORLFianium::BORLFianiumCntrl()
{
    switch(iFunctn)
    {
        case 0:
            BORLFianiumConnect();
            break;
        case 1:
            BORLFianiumPowerScale();
            BORLFianiumWlngtScale();
            BORLFianiumSetWavelenght();
            BORLFianiumSetPower();
        break;
        case 2:
            BORLFianiumPowerScale();
            BORLFianiumSetWavelenght();
            BORLFianiumSetPower();
        break;
    }
        qDebug()<<FeedbackCodes;
}


