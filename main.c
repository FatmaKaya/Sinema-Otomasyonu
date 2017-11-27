#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum
{
    Bilet=1,
    Hasilat,
    Izlenme
} Bilgiler;
typedef enum
{
    Red=1,
    Green,
    Blue
} Salon;
typedef enum
{
    ogrenci,
    tam
} Odeme;
typedef struct
{

    char RED[5][50];
    char GREEN[5][50];
    char BLUE[5][50];
    char YELLOW[5][50];

} SALONLAR;
int main()
{
    char a[50],b;

    FILE *koltuklarRED,*koltuklarGREEN,*koltuklarBLUE, *hasilat;
    int i,j,ucret=0,syc=0;
    Bilgiler blg;
    Salon sln;
    Odeme Odurum;
    SALONLAR secilensalon, *psecilensalon;
    psecilensalon=&secilensalon;

    FILE *sifre;
    sifre=fopen("sifre.txt","r");
    if(sifre==NULL)
    {
        printf("Dosya hatasi!");
        exit(0);
    }
    printf("++LUTFEN SIFRENIZI GIRINIZ:(sifre=odev)");
    gets(a);
    for(i=0; i<strlen(a); i++)
    {
        b=(char)(((int)a[i]-65+5)%26+65);
        if(b!=getc(sifre))
        {
            printf("yanlis sifre!");
            exit(0);
        }
    }
    fclose(sifre);

    /*koltuklarRED=fopen("koltuklarRED.txt","w");
    if(koltuklarRED==NULL)
    {
        printf("Dosyada hata var!");
        exit(1);
    }
    for(i=1; i<6; i++)
    {
        for(j=1; j<51; j++)
        {
            fputc('0',koltuklarRED);
        }
    }
    fclose(koltuklarRED);

    koltuklarGREEN=fopen("koltuklarGREEN.txt","w");
    if(koltuklarGREEN==NULL)
    {
        printf("Dosyada hata var!");
        exit(1);
    }
    for(i=1; i<6; i++)
    {
        for(j=1; j<51; j++)
        {
            fputc('0',koltuklarGREEN);
        }
    }
    fclose(koltuklarGREEN);

      koltuklarBLUE=fopen("koltuklarBLUE.txt","w");
      if(koltuklarBLUE==NULL)
      {
          printf("Dosyada hata var!");
          exit(1);
      }
      for(i=1; i<6; i++)
      {
          for(j=1; j<51; j++)
          {
              fputc('0',koltuklarBLUE);
          }
      }
      fclose(koltuklarBLUE);

      hasilat=fopen("Hasilat.txt","w");
            if(hasilat==NULL)
            {
                printf("Dosyada hata var!");
                exit(0);
            }
            fprintf(hasilat,"%d",ucret);
            fclose(hasilat);*/

    printf("\n------------------SINEMA OTOMASYONU------------------\n");
    printf("--  Bilet almak icin-->1 Hasilat bilgisi icin-->2  --\n");
    printf("--       Matinalarin izlenme sayisi icin-->3       --\n");
    printf("-----------------------------------------------------\n");
    scanf("%d",&blg);
    if(blg==1)
    {
        printf("\n             BILET ALMA ISLEMLERI                 \n");
        printf("--      ++++++++++Salonlar++++++++++             --\n");
        printf("--   +RED --> 1\t+GREEN -->2\t+BLUE -->3       --\n");
        printf("---------------------------------------------------\n\n");
        printf("++Hangi salonda girmek istediginizi seciniz:");
        scanf("%d",&sln);
        if(sln==1)
        {

            koltuklarRED=fopen("koltuklarRED.txt","r");
            if(koltuklarRED==NULL)
            {
                printf("Dosyada hata var!");
                exit(1);
            }
            for(i=1; i<6; i++)
            {
                for(j=1; j<51; j++)
                {
                    psecilensalon->RED[i][j]=fgetc(koltuklarRED);
                }
            }
            fclose(koltuklarRED);

            printf("  *RED salonunda kacinci matinede girmek istersiniz:(1,2,3,4,5)");
            scanf("%d",&i);

            koltuklarRED=fopen("koltuklarRED.txt","w+");
            if(koltuklarRED==NULL)
            {
                printf("Dosyada hata var!");
                exit(1);
            }
            for(j=1; j<51; j++)
            {
                if(psecilensalon->RED[i][j]=='0')
                {
                    psecilensalon->RED[i][j]='1';
                    break;
                }
            }
            printf("\nRED salonu %d matine %d. koltukta yeriniz ayrilmistir.\n",i,j);
            for(i=1; i<6; i++)
            {
                for(j=1; j<51; j++)
                {
                    if(psecilensalon->RED[i][j]=='1')
                        putc('1',koltuklarRED);
                    else
                        putc('0',koltuklarRED);
                }
            }
            fclose(koltuklarRED);

        }
        else if(sln==2)
        {

            koltuklarGREEN=fopen("koltuklarGREEN.txt","r");
            if(koltuklarGREEN==NULL)
            {
                printf("Dosyada hata var!");
                exit(1);
            }
            for(i=1; i<6; i++)
            {
                for(j=1; j<51; j++)
                {
                    psecilensalon->GREEN[i][j]=fgetc(koltuklarGREEN);
                }
            }

            fclose(koltuklarGREEN);
            printf("  *GREEN salonunda kacinci matinede girmek istersiniz:(1,2,3,4,5)");
            scanf("%d",&i);

            koltuklarGREEN=fopen("koltuklarGREEN.txt","w+");
            if(koltuklarGREEN==NULL)
            {
                printf("Dosyada hata var!");
                exit(1);
            }
            for(j=1; j<51; j++)
            {
                if(psecilensalon->GREEN[i][j]=='0')
                {
                    psecilensalon->GREEN[i][j]='1';
                    break;
                }
            }
            printf("\nGREEN salonu %d matine %d. koltukta yeriniz ayrilmistir.\n",i,j);
            for(i=1; i<6; i++)
            {
                for(j=1; j<51; j++)
                {
                    if(psecilensalon->GREEN[i][j]=='1')
                        putc('1',koltuklarGREEN);
                    else
                        putc('0',koltuklarGREEN);
                }
            }
            fclose(koltuklarGREEN);

        }
        else if(sln==3)
        {

            koltuklarBLUE=fopen("koltuklarBLUE.txt","r");
            if(koltuklarBLUE==NULL)
            {
                printf("Dosyada hata var!");
                exit(1);
            }
            for(i=1; i<6; i++)
            {
                for(j=1; j<51; j++)
                {
                    psecilensalon->BLUE[i][j]=fgetc(koltuklarBLUE);
                }
            }

            fclose(koltuklarBLUE);
            printf("  *BLUE salonunda kacinci matinede girmek istersiniz:(1,2,3,4,5)");
            scanf("%d",&i);

            koltuklarBLUE=fopen("koltuklarBLUE.txt","w+");
            if(koltuklarBLUE==NULL)
            {
                printf("Dosyada hata var!");
                exit(1);
            }
            for(j=1; j<51; j++)
            {
                if(psecilensalon->BLUE[i][j]=='0')
                {
                    psecilensalon->BLUE[i][j]='1';
                    break;
                }
            }
            printf("\nBLUE salonu %d matine %d. koltukta yeriniz ayrilmistir.\n",i,j);
            for(i=1; i<6; i++)
            {
                for(j=1; j<51; j++)
                {
                    if(psecilensalon->BLUE[i][j]=='1')
                        putc('1',koltuklarBLUE);
                    else
                        putc('0',koltuklarBLUE);
                }
            }
            fclose(koltuklarBLUE);

        }
        else
        {
            printf("OYLE BIR SALON YOKTUR!");
            return 0;
        }

        printf("\n  *Odeme durumunuzu belirtiniz:(Ogrenci->0 / Tam->1)");
        scanf("%d",&Odurum);
        switch(Odurum)
        {
        case 0:
            printf("\nVereceginiz ucret:%d TL.\n TESEKKUR EDERIZ.\n",20);
            hasilat=fopen("Hasilat.txt","r");
            if(hasilat==NULL)
            {
                printf("Dosyada hata var!");
                exit(0);
            }
            fscanf(hasilat,"%d",&ucret);
            fclose(hasilat);

            hasilat=fopen("Hasilat.txt","w+");
            if(hasilat==NULL)
            {
                printf("Dosyada hata var!");
                exit(0);
            }
            ucret=ucret+20;
            fprintf(hasilat,"%d",ucret);
            fclose(hasilat);
            break;
        case 1:
            printf("\nVereceginiz ucret:%d TL.\n TESEKKUR EDERIZ.\n",30);
            hasilat=fopen("Hasilat.txt","r");
            if(hasilat==NULL)
            {
                printf("Dosyada hata var!");
                exit(0);
            }
            fscanf(hasilat,"%d",&ucret);
            fclose(hasilat);
            hasilat=fopen("Hasilat.txt","w+");
            if(hasilat==NULL)
            {
                printf("Dosyada hata var!");
                exit(0);
            }
            ucret=ucret+30;
            fprintf(hasilat,"%d",ucret);
            fclose(hasilat);
            break;
        default:
            printf("OYLE BIR ODEME DURUMU YOK!");
            break;
        }

    }
    else if(blg==2)
    {
        hasilat=fopen("Hasilat.txt","r");
        if(hasilat==NULL)
        {
            printf("Dosyada hata var!");
            exit(0);
        }
        fscanf(hasilat,"%d",&ucret);
        fclose(hasilat);
        printf("HASILAT=%d TL'dir.\n",ucret);
    }
    else if(blg==3)
    {

        koltuklarRED=fopen("koltuklarRED.txt","r");
        if(koltuklarRED==NULL)
        {
            printf("Dosyada hata var!");
            exit(1);
        }
        for(i=1; i<6; i++)
        {
            for(j=1; j<51; j++)
            {
                psecilensalon->RED[i][j]=fgetc(koltuklarRED);
            }
        }
        fclose(koltuklarRED);

        printf("\n--             RED salonunda;             --\n--");
        for(i=1; i<6; i++)
        {
            for(j=1; j<51; j++)
            {
                if(psecilensalon->RED[i][j]=='1')
                    syc++;

            }
            printf("--\n--  %d. matina %d kisi tarafindan izlendi.  --\n--",i,syc);
            syc=0;
        }

        koltuklarGREEN=fopen("koltuklarGREEN.txt","r");
        if(koltuklarGREEN==NULL)
        {
            printf("Dosyada hata var!");
            exit(1);
        }
        for(i=1; i<6; i++)
        {
            for(j=1; j<51; j++)
            {
                psecilensalon->GREEN[i][j]=fgetc(koltuklarGREEN);
            }
        }
        fclose(koltuklarGREEN);
        printf("\n--           GREEN salonunda;             --\n--");
        for(i=1; i<6; i++)
        {
            for(j=1; j<51; j++)
            {
                if(psecilensalon->GREEN[i][j]=='1')
                    syc++;

            }
            printf("--\n--  %d. matina %d kisi tarafindan izlendi.  --\n--",i,syc);
            syc=0;
        }

        koltuklarBLUE=fopen("koltuklarBLUE.txt","r");
        if(koltuklarBLUE==NULL)
        {
            printf("Dosyada hata var!");
            exit(1);
        }
        for(i=1; i<6; i++)
        {
            for(j=1; j<51; j++)
            {
                psecilensalon->BLUE[i][j]=fgetc(koltuklarBLUE);
            }
        }
        fclose(koltuklarBLUE);

        printf("\n--            BLUE salonunda;             --\n--");
        for(i=1; i<6; i++)
        {
            for(j=1; j<51; j++)
            {
                if(psecilensalon->BLUE[i][j]=='1')
                    syc++;

            }
            printf("--\n--  %d. matina %d kisi tarafindan izlendi.  --\n--",i,syc);
            syc=0;
        }
    }
    else printf("OYLE BIR SECENEK YOK!");
    return 0;
}
