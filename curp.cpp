#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include "libreria.h"

void uncucadi(char mote[4], char mote2[3]);
int compnom(char carac[30]);
void cididiec(char data[6], char trastras[1]);
void onoce(char sexo[1]);
void estd(char carac[2]);
int finalo(char aponomb[30], int n, int ini);
int inicio(char apellonomb[30], int n);
int compdedal(char part[11]);
int busvoc(char nmbraplld[30], int ini, int fina);
int busccons(char aplldnmbr[30], int ini, int fina);
int incomv(char palabra[6]);
int main()
{
    int fina;
    char nomb1[4], nomb2[3], fecha[6], gene[1], estad[2], penultimo[1], curp[17];
    srand(time(NULL));
    nomb1[4]='\0';
    nomb2[3]='\0';
    fecha[6]='\0';
    gene[1]='\0';
    estad[2]='\0';
    penultimo[1]='\0';
    uncucadi(nomb1, nomb2);
    cididiec(fecha, penultimo);
    onoce(gene);
    estd(estad);
    curp[0]=nomb1[0];
    curp[1]=nomb1[1];
    curp[2]=nomb1[2];
    curp[3]=nomb1[3];
    curp[4]=fecha[0];
    curp[5]=fecha[1];
    curp[6]=fecha[2];
    curp[7]=fecha[3];
    curp[8]=fecha[4];
    curp[9]=fecha[5];
    curp[10]=gene[0];
    curp[11]=estad[0];
    curp[12]=estad[1];
    curp[13]=nomb2[0];
    curp[14]=nomb2[1];
    curp[15]=nomb2[2];
    curp[16]=penultimo[0];
    curp[17]='\0';
    fina=rand()%10;
    printf("%s%d", curp, fina);   
    return 0;
}

void uncucadi(char mote[4], char mote2[3])
{
    char nombre[30], nombre2[30], appat[20], apmat[30];
    int opc, opc2, l1, l2, l3, n, m, o;
    int inic1, inic2, inic3, fin1, fin2, fin3;
    vali_cad(nombre, "Escribe tu primer nombre siguiendo las siguientes indicaciones\nEscribe las vocales sin ascento\nSimbolos como -, / o . estan permitidos ");
    opc=vali_num(1, 2, "Tienes segundo nombre? \n1=si\n2=no ", "Esa opcion no es valida");
    if(opc==1)
    {
        vali_cad(nombre2, "Escribe tu segundo nombre siguiendo las siguientes indicaciones\nEscribe las vocales sin ascento\nSimbolos como -, / o . estan permitidos ");
        n=compnom(nombre);
        if(n==1)
        {
            strcpy(nombre, nombre2);
        }
    }
    opc2=vali_num(1, 3, "Sobre tu(s) apellidos...\n1=tengo ambos apellidos\n2=Solo tengo uno\n3=No tengo apellidos ", "Esa opcion no existe");
    switch (opc2)
    {
    case 1:
        vali_cad(appat, "Escribe tu primer apellido siguiendo las siguientes indicaciones\nEscribe las vocales sin ascento\nSimbolos como -, / o . estan permitidos ");
        vali_cad(apmat,"Escribe tu segundo apellido siguiendo las siguientes indicaciones\nEscribe las vocales sin ascento\nSimbolos como -, / o . estan permitidos ");
        break;
    case 2:
    vali_cad(appat,"Escribe tu unico apellido siguiendo las siguientes indicaciones\nEscribe las vocales sin ascento\nSimbolos como -, / o . estan permitidos ");
    strcpy(apmat, "XXXXX");
    break;
    default:
    strcpy(appat, "XXXXX");
    strcpy(apmat, "XXXXX");
    break;
    }
    l1=largo_cadena(nombre);
    l2=largo_cadena(appat);
    l3=largo_cadena(apmat);
    inic1=inicio(nombre, l1);
    inic2=inicio(appat, l2);
    inic3=inicio(apmat, l3);
    fin1=finalo(nombre, l1, inic1);
    fin2=finalo(appat, l2, inic2);
    fin3=finalo(apmat, l3, inic3);
    //apellido paterno
    if(appat[inic2]>='A')
    {
        mote[0]=appat[inic2];
    }
    else
    {
        mote[0]='X';
    }
    m=busvoc(appat, inic2, fin2);
    if(m!=-1)
    {
        mote[1]=appat[m];
    }
    else
    {
        mote[1]='X';
    }
    o=busccons(appat, inic2, fin2);
    if(o != -1)
    {
        mote2[0]=appat[o];
    }
    else
    {
        mote2[0]='X';
    }
    //apellido materno
    if(apmat[inic3]>='A')
    {
        mote[2]=apmat[inic3];
    }
    else
    {
        mote[2]='X';
    }
    m=busccons(apmat, inic3, fin3);
    if(m != -1)
    {
        mote2[1]=apmat[m];
    }
    else
    {
        mote2[1]='X';
    }
    //nombre
    if(nombre[inic1]>='A')
    {
        mote[3]=nombre[inic1];
    }
    else
    {
        mote[3]='X';
    }
    m=busccons(nombre, inic1, fin1);
    if(m != -1)
    {
        mote2[2]=nombre[m];
    }
    else
    {
        mote2[2]='X';
    }
    mote[4]='\0';
    //palabras incomvenientes
    m=incomv(mote);
    if(m==1)
    {
        mote[1]='X';
    }
}

void cididiec(char data[6], char trastras[1])
{
    int anio, mes, dia;
    char ano[6], meses[6], dias[6];
    anio=vali_num2(1907, 2023, "Ingresa tu anio de nacimiento (no agregar 0 a la izquierda) ", "Asegurese de ingresar el anio de una persona viva ", ano, 4);
    mes=vali_num2(1, 12, "ingrese el numero de mes de nacimiento \n(SI EL NUMERO ES MENOR A 10, ESCRIBELO CON UN 0 A LA IZQUIERDA: 01, 02, 03, ETC) ", "Recuerda que no hay mas de 12 ni menos de 1 mes ", meses, 2);
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        dia=vali_num2(1, 31,"Escribe tu dia de nacimiento (si es menor a 10: 01, 02, 03, etc) ", "Tu mes empiza el 1 y termina el 31", dias, 2);
    }
    if(mes==4 || mes==6 || mes==9 || mes==11)
    {
        dia=vali_num2(1, 30,"Escribe tu dia de nacimiento (si es menor a 10: 01, 02, 03, etc) ", "Tu mes empiza el 1 y termina el 30", dias, 2);
    }
    if(mes==2)
    {
        if(anio%4==0)
        {
            dia=vali_num2(1, 29,"Escribe tu dia de nacimiento (si es menor a 10: 01, 02, 03, etc) ", "Tu mes empiza el 1 y termina el 29", dias, 2);
        }
        else
        {
            dia=vali_num2(1, 28,"Escribe tu dia de nacimiento (si es menor a 10: 01, 02, 03, etc) ", "Tu mes empiza el 1 y termina el 28", dias, 2);
        }
    }
    data[0]=ano[2];
    data[1]=ano[3];
    data[2]=meses[0];
    data[3]=meses[1];
    data[4]=dias[0];
    data[5]=dias[1];
    if(anio<2000)
    {
        trastras[0]='0';
    }
    else
    {
        if(anio<2010)
        {
            trastras[0]='A';
        }
        else
        {
            if(anio<2020)
            {
                trastras[0]='B';
            }
            else
            {
                trastras[0]='C';
            }
        }
    }
}

void onoce(char sexo[1])
{
    int sex;
    sex=vali_num(1, 2, "Selecciona tu genero\n1 Masculino\n2 Femenino ", "Por el momento solo manejamos dos generos");
    if(sex==1)
    {
        sexo[0]='H';
    }
    else
    {
        sexo[0]='M';
    }
}

void estd(char carac[2])
{
    int i;
    char estado[][4]={{"AS"},{"BC"},{"BS"},{"CC"},{"CL"},{"CM"},{"CS"},{"CH"},{"DF"},{"DG"},{"GT"},{"GR"},{"HG"},{"JC"},{"MC"},{"MN"},{"MS"},{"NT"},{"NL"},{"OC"},{"PL"},{"QT"},{"QR"},{"SP"},{"SL"},{"SR"},{"TC"},{"TS"},{"TL"},{"VZ"},{"YN"},{"ZS"},{"NE"}};
    char estador[][30]={{"AGUAS CALIENTES"},{"BAJA CALIFORNIA"},{"BAJA CALIFORNIA SUR"},{"CAMPECHE"},{"COAHUILA"},{"COLIMA"},{"CHIAPAS"},{"CHIHUAHA"},{"DISTRITO FEDERAL"},{"DURANGO"},{"GUANAJUATO"},{"GUERRERO"},{"HIDALGO"},{"JALISCO"},{"MEXICO"},{"MICHOACAN"},{"MORELOS"},{"NAYARIT"},{"NUEVO LEON"},{"OAXACA"},{"PUEBLA"},{"QUERETARO"},{"QUINTANA ROO"},{"SAN LUIS POTOSI"},{"SINALOA"},{"SONORA"},{"TABASCO"},{"TAMAULIPAS"},{"TLAXCALA"},{"VERACRUZ"},{"YUCATAN"},{"ZACATECAS"},{"NACIDO EN EL EXTRANJERO"}};
    int est, j;
    est=-1;
    system("CLS");
    while (est==-1)
    {
        printf("Lista de los estados de Mexico\n");
        for(i=0;i<33;i++)
        {
            printf("%d |%s|\n", i, estador[i]);
        }
        system("PAUSE");
        est=vali_num(-1,32, "Elija el numero de su estado o si quiere volver a ver la lista escriba -1 ", "Ese numero no esta en la lista");
    }
    carac[0]=estado[est][0];
    carac[1]=estado[est][1];
    
}

int compnom(char carac[30])
{
    int i;
    char marjos[][10]={{"MARIA"},{"MA."},{"MA"},{"M."},{"M"},{"JOSE"},{"J."},{"J"}};
    for(i=0;i<8;i++)
    {
        if(strcmpi(carac,marjos[i])==0)
        {
            return 1;
        }
    }
    return 0;
}

int inicio(char apellonomb[30], int n)
{
    int i,j, k, x, m, resu;
    char prueba1[11];
    m=1;
    k=0;
    i=0;
    resu=0;
    x=0;
    do
    {
        if(apellonomb[i]==' ')
        {
            x=0;
            for(j=k;j<i;j++)
            {
                prueba1[x]=apellonomb[j];
                x++;
                k++;
            }
            prueba1[x]='\0';
            m=compdedal(prueba1);
            if(m==1)
            {
                resu=i+1;
                k=k+1;
                strcpy(prueba1,"x");
            }
            else
            {
                return resu;
            }
           
        }
        i=i+1;
    } while (i<n);
    return resu;
    
}

int compdedal(char carac[11])
{
    int i;
    char espacio[][5]={{"DA"},{"DAS"},{"DE"},{"DEL"},{"DER"},{"DI"},{"DIE"},{"DD"},{"Y"},{"EL"},{"LA"},{"LOS"},{"LAS"},{"LE"},{"LES"},{"MAC"},{"MC"},{"VAN"},{"VON"}};
    for(i=0;i<19;i++)
    {
        if(strcmpi(carac,espacio[i])==0)
        {
            return 1;
        }
    }
    return 0;
}

int finalo(char aponomb[30], int n, int ini)
{
    int i;
    int finale;
    for(i=ini;i<n;i++)
    {
        if(aponomb[i]==' ' || aponomb[i]=='-')
        {
            finale=i;
            return finale;
        }
    }
    return n;
}



int busvoc(char nmbraplld[30], int ini, int fina)
{
    int i;

    for(i=ini+1;i<fina-1;i++)
    {
        if(nmbraplld[i]=='A' || nmbraplld[i]=='E' || nmbraplld[i]=='I' || nmbraplld[i]=='O' || nmbraplld[i]=='U')
        {
            if(nmbraplld[i-1]<'A')
            {
                return -1;
            }
            else
            {
                return i;
            }
        }
    }

    return -1;
}
int busccons(char aplldnmbr[30], int ini, int fina)
{
    int i;

    for(i=ini+1;i<fina-1;i++)
    {
        if(aplldnmbr[i]!='A')
        {
            if(aplldnmbr[i]!='E')
            {
                if(aplldnmbr[i]!='I')
                {
                    if(aplldnmbr[i]!='O')
                    {
                        if(aplldnmbr[i]!='U')
                        {
                            return i;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int incomv(char palabra[6])
{
    int i;
    char groce[][6]={{"BACA"},{"BAKA"},{"BUEI"},{"BUEY"},{"CACA"},{"CACO"},{"CAGA"},{"CAKA"},{"CAKO"},{"COGE"},{"COGE"},{"COGI"},{"COJA"},{"COJE"},{"COJI"},{"COJO"},{"COLA"},{"CULO"},{"FALO"},{"FETO"},{"GETA"},{"GUEI"},{"GUEY"},{"JETA"},{"JOTO"},{"KACA"},{"KACO"},{"KAGA"},{"KAGO"},{"KAKA"},{"KAKO"},{"KOGE"},{"KOGI"},{"KOJA"},{"KOJE"},{"KOJI"},{"KOJO"},{"KOLA"},{"KULO"},{"LILO"},{"LOCA"},{"LOCO"},{"LOKA"},{"LOKO"},{"MAME"},{"MAMO"},{"MEAR"},{"MEAS"},{"MEON"},{"MIAR"},{"MION"},{"MOCO"},{"MOKO"},{"MULA"},{"MULO"},{"NACA"},{"NACO"},{"PEDA"},{"PEDO"},{"PENE"},{"PIPI"},{"PITO"},{"POPO"},{"PUTA"},{"PUTO"},{"QULO"},{"RATA"},{"ROBA"},{"ROBE"},{"ROBO"},{"RUIN"},{"SENO"},{"TETA"},{"VACA"},{"VAGA"},{"VAKA"},{"VUEI"},{"VUEY"},{"WUEI"},{"WUEY"}};
    for(i=0;i<19;i++)
    {
        if(strcmpi(palabra, groce[i])==0)
        {
            return 1;
        }
    }
    return 0;
}