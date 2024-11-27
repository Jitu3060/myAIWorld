#define p "341348"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

//DECLARING ALL THE GLOBAL VARIABLE IN USE
FILE* q;
int w[14], t[] = { 50,30,10,90 }, count_heart = 0, count_body = 0;
int xray[5];
int stetho[3];
int input_val[18];
float chf, rf, ao, go, bc, gd, cx, ecgsum = 0, two_dsum = 0, presg_sum = 0, color, dop_aortic;
float m_mode_sum, mv1, two_d[3];
int i, j = 0;
int sys_wt[44];
float threshold[] = { 1.8808,5.8902,6.3588,2.9942,1.1526,908.4165,1031.1945 };


//DEFINING TYPE-1 NEURON
//--------------------------------------
struct neuron1
{
    float th_val;
    float working_val;
    float inp_w[6];
};
struct neuron1 SHD, CHD, BHD;

//DEFINING TYPE-2 NEURON
//----------------------------------------
struct neuron2
{
    float th_val;
    float working_val;
    float inp_w[5];
};
struct neuron2 echo_struct, echo_behav;

//DEFINING TYPE-3 NEURON
//----------------------------------------
struct neuron3
{
    float th_val;
    float working_val;
    float inp_w[8];
    int outp_val;
};
struct neuron3 steno, regur;



//DECLARING ALL GLOBAL FUNCTIONS


void gen_wt()
{
    int i;
    for (i = 0; i < 44; i++)
        sys_wt[i] = random(54);
}

//TRICUSPID STENOSIS GRAPH
void tristen()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(21);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(24);
    settextstyle(1, 0, 1);
    outtextxy(80, 200, "YOU ARE SUFFERING FROM TRICUSPID VALVE STENOSIS");
    setcolor(31);
    setbkcolor(16);
    delay(10000);
    cleardevice();
    start_menu();
}

//POLUMONARY STENOSIS GRAPH
void polumsten()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(33);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(18);
    settextstyle(1, 0, 1);
    outtextxy(55, 200, "YOU ARE SUFFERING FROM PULMONARY VALVE STENOSIS ");
    setcolor(31);
    setbkcolor(05);
    delay(10000);
    cleardevice();
    start_menu();
}


//MITRAL STENOSIS
void mitral_steno()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(6);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(10);
    settextstyle(1, 0, 1);
    outtextxy(100, 200, "YOU ARE SUFFERING FROM MITRAL VALVE STENOSIS");
    setcolor(31);
    setbkcolor(05);
    delay(10000);
    cleardevice();
    start_menu();
}


//PROLAPSE GRAPHICS
void plolapse()
{
    int gdriver = DETECT, gmode, mx, my, i, branch;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(7);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i < 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(10);
    settextstyle(1, 0, 1);
    outtextxy(80, 200, "YOU ARE SUFFERING FROM MITRAL VALVE PROPLAPSE");
    setcolor(31);
    setbkcolor(06);
    setcolor(GREEN);
    delay(10000);
    cleardevice();
    start_menu();
}

//STENOSIS GRAPHICS
void aorsten()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(4);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(14);
    settextstyle(1, 0, 1);
    outtextxy(100, 200, "YOU ARE SUFFERING FROM AORTIC VALVE STENOSIS");
    setcolor(31);
    setbkcolor(02);
    delay(10000);
    cleardevice();
    start_menu();
}

//AORTIC VALVE REGURGITATION
void aortreg()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(14);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(26);
    settextstyle(1, 0, 1);
    outtextxy(80, 200, "YOU ARE SUFFERING FROM AORTIC VALVE REGURGITATION");
    setcolor(31);
    setbkcolor(06);
    delay(10000);
    cleardevice();
    start_menu();
    getch();
}

//MITRAL VALVE REGURGITATION
void mitraregur()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(21);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(01);
    settextstyle(1, 0, 1);
    outtextxy(80, 200, "YOU ARE SUFFERING FROM MITRAL VALVE REGURGITATION");
    setcolor(31);
    setbkcolor(00);
    delay(10000);
    cleardevice();
    start_menu();
}

//PULMONARY VALVE REGURGITATION
void polumregur()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(23);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(33);
    settextstyle(1, 0, 1);
    outtextxy(40, 200, "YOU ARE SUFFERING FROM PULMONARY VALVE REGURGITATION ");
    setcolor(31);
    setbkcolor(03);
    delay(10000);
    cleardevice();
    start_menu();
}

//TRICUSPID VALVE REGURGITATION
void tricregur()
{
    int gdriver = DETECT, gmode, mx, my, i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(23);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i <= 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(25);
    settextstyle(1, 0, 1);
    outtextxy(55, 200, "YOU ARE SUFFERING FROM TRICUSPID VALVE REGURGITATION");
    setcolor(31);
    setbkcolor(18);
    delay(10000);
    cleardevice();
    start_menu();
}


//----------------------- EVALUATING ALL WORKING VALUE
       //FOR ALL NEURAL NODES-----------------------------------
void last_lay();

void eval_shd()
{
    float shd;
    shd = SHD.inp_w[0] * chf + SHD.inp_w[1] * rf + SHD.inp_w[2] * ao
        + SHD.inp_w[3] * go + SHD.inp_w[4] * bc + SHD.inp_w[5] * gd;
    SHD.working_val = shd / 100;
}

void eval_bhd()
{
    float bhd;
    bhd = BHD.inp_w[0] * chf + BHD.inp_w[1] * rf + BHD.inp_w[2] * ao
        + BHD.inp_w[3] * go + BHD.inp_w[4] * bc + BHD.inp_w[5] * gd;
    BHD.working_val = bhd / 100;
}

void eval_chd()
{
    float chd;
    chd = CHD.inp_w[0] * chf + CHD.inp_w[1] * rf + CHD.inp_w[2] * ao
        + CHD.inp_w[3] * go + CHD.inp_w[4] * bc + CHD.inp_w[5] * gd;
    SHD.working_val = chd / 100;
}


void eval_echo_struct()
{
    float res;
    res = echo_struct.inp_w[0] * presg_sum +
        echo_struct.inp_w[1] * dop_aortic +
        echo_struct.inp_w[2] * two_dsum +
        echo_struct.inp_w[3] * m_mode_sum +
        echo_struct.inp_w[4] * color;
    echo_struct.working_val = res / 100;
}

void eval_echo_behav()
{
    float res;
    res = echo_behav.inp_w[0] * presg_sum +
        echo_behav.inp_w[1] * dop_aortic +
        echo_behav.inp_w[2] * two_dsum +
        echo_behav.inp_w[3] * m_mode_sum +
        echo_behav.inp_w[4] * color;
    echo_behav.working_val = res / 100;
}

void eval_steno()
{
    float sten;
    sten = steno.inp_w[0] * echo_struct.working_val +
        steno.inp_w[1] * echo_behav.working_val +
        steno.inp_w[2] * ecgsum +
        steno.inp_w[3] * cx +
        steno.inp_w[4] * SHD.working_val +
        steno.inp_w[5] * BHD.working_val +
        steno.inp_w[6] * CHD.working_val +
        steno.inp_w[7] * mv1;
    steno.working_val = sten;
}

void eval_regur()
{
    float rgr;
    rgr = regur.inp_w[0] * echo_struct.working_val +
        regur.inp_w[1] * echo_behav.working_val +
        regur.inp_w[2] * ecgsum +
        regur.inp_w[3] * cx +
        regur.inp_w[4] * SHD.working_val +
        regur.inp_w[5] * BHD.working_val +
        regur.inp_w[6] * CHD.working_val +
        regur.inp_w[7] * mv1;
    regur.working_val = rgr;
}


//PARSING THE NEURAL NETWORK
void parse()
{
    eval_shd();
    eval_bhd();
    eval_chd();
    eval_echo_struct();
    eval_echo_behav();
    eval_steno();
    eval_regur();
    last_lay();
}


//MANAGING BEFORE LAST LAYER BY ADJUSTING WEIGHTS
//-------------------------------------------------
void  before_last_lay()
{
    float action_val;
    int i;
    if ((SHD.th_val * 100) < SHD.working_val)       //adjusting Structural heart failure neuron
    {
        action_val = (SHD.working_val - (SHD.th_val * 100)) / 6;
        for (i = 0; i < 6; i++)
            SHD.inp_w[i] = SHD.inp_w[i] - action_val;
    }
    else
    {
        action_val = ((SHD.th_val * 100) - SHD.working_val) / 6;
        for (i = 0; i < 6; i++)
            SHD.inp_w[i] = SHD.inp_w[i] + action_val;
    }
    if ((BHD.th_val * 100) < BHD.working_val)  //adjusting Behavioural heart deformity
    {
        action_val = (BHD.working_val - (BHD.th_val * 100)) / 6;
        for (i = 0; i < 6; i++)
            BHD.inp_w[i] = BHD.inp_w[i] - action_val;
    }
    else
    {
        action_val = ((BHD.th_val * 100) - BHD.working_val) / 6;
        for (i = 0; i < 6; i++)
            BHD.inp_w[i] = BHD.inp_w[i] + action_val;
    }
    if ((CHD.th_val * 100) < CHD.working_val)     //adjusting Congenital Heart deformity
    {
        action_val = (CHD.working_val - (CHD.th_val * 100)) / 6;
        for (i = 0; i < 6; i++)
            CHD.inp_w[i] = CHD.inp_w[i] - action_val;
    }
    else
    {
        action_val = ((CHD.th_val * 100) - CHD.working_val) / 6;
        for (i = 0; i < 6; i++)
            CHD.inp_w[i] = CHD.inp_w[i] + action_val;
    }
    if ((echo_struct.th_val * 100) < echo_struct.working_val)      //adjusting Echocardiography structure
    {
        action_val = (echo_struct.working_val - (echo_struct.th_val * 100)) / 6;
        for (i = 0; i < 5; i++)
            echo_struct.inp_w[i] = echo_struct.inp_w[i] - action_val;
    }
    else
    {
        action_val = ((echo_struct.th_val * 100) - echo_struct.working_val) / 6;
        for (i = 0; i < 5; i++)
            echo_struct.inp_w[i] = echo_struct.inp_w[i] + action_val;
    }
    if ((echo_behav.th_val * 100) < echo_behav.working_val)      //adjusting Echocardiography Behaviour
    {
        action_val = (echo_behav.working_val - (echo_behav.th_val * 100)) / 6;
        for (i = 0; i < 5; i++)
            echo_behav.inp_w[i] = echo_behav.inp_w[i] - action_val;
    }
    else
    {
        action_val = ((echo_behav.th_val * 100) - echo_behav.working_val) / 6;
        for (i = 0; i < 5; i++)
            echo_behav.inp_w[i] = echo_behav.inp_w[i] + action_val;
    }
    parse();
}

//MANAGING LAST LAYER WORKING BY ADJUSTING THE WEIGHTS
//-------------------------------------------------------
void last_lay()
{
    float action_val;
    int i;
    if (steno.working_val > steno.th_val && regur.working_val > regur.th_val)
    {
        //SYSTEM IS IN UNSTABLE STATE
        //ADJUSTING STENOTIC & REGURTIC NEURON WEIGHTS
        action_val = (steno.working_val - steno.th_val) / 8;
        for (i = 0; i < 8; i++)
            steno.inp_w[i] = steno.inp_w[i] - action_val;
        action_val = (regur.working_val - regur.th_val) / 8;
        for (i = 0; i < 8; i++)
            regur.inp_w[i] = regur.inp_w[i] - action_val;
        //CALL TO PREVIOUS NEURON SETS FOR THEIR WEIGHT ADJUSTMENT
        before_last_lay();
    }
    else
    {
        if (steno.working_val < steno.th_val && regur.working_val < regur.th_val)
        {
            //SYSTEM IS IN UNSTABLE STATE
            //ADJUSTING STENOTIC & REGURTIC NEURON WEIGHTS
            action_val = (steno.th_val - steno.working_val) / 8;
            for (i = 0; i < 8; i++)
                steno.inp_w[i] = steno.inp_w[i] + action_val;
            action_val = (regur.th_val - regur.working_val) / 8;
            for (i = 0; i < 8; i++)
                regur.inp_w[i] = regur.inp_w[i] + action_val;
            //CALL TO PREVIOUS NEURON SETS FOR THEIR WEIGHT ADJUSTMENT
            before_last_lay();
        }
        else
        {
            if (steno.working_val > steno.th_val && regur.working_val < regur.th_val)
            {
                steno.outp_val = 1;
                regur.outp_val = 0;
            }
            if (steno.working_val<steno.th_val && regur.working_val>regur.th_val)
            {
                steno.outp_val = 0;
                regur.outp_val = 1;
            }
        }
    }
}

void final_eval()
{
    int xraycheck, e;
    if (cx == 1)
        xraycheck = 1;
    if (cx == 2)
        xraycheck = 0;
    if (cx == 3)
        xraycheck = 10;
    if (cx == 2)
        xraycheck = 11;

    if (two_d[0] == 6)
        //call to mitral prolapse
        plolapse();

    if (steno.outp_val == 1 && xraycheck == 1)
        //call to aortic stenosis graphics
        aorsten();

    if (steno.outp_val == 1 && xraycheck == 2)
        //call to mitral stenosis graphics
        mitral_steno();

    if (steno.outp_val == 1 && xraycheck == 3)
        //call to polumonary stenosis graphics
        polumsten();

    if (steno.outp_val == 1 && xraycheck == 4)
        //call to tricuspid stenosis graphics
        tristen();

    if (regur.outp_val == 1 && xraycheck == 1)
        //call to aortic regurtation graphics
        aortreg();

    if (regur.outp_val == 1 && xraycheck == 2)
        //call to mitral regurtation graphics
        mitraregur();

    if (regur.outp_val == 1 && xraycheck == 3)
        //call to polumonary regurtation graphics
        polumregur();

    if (regur.outp_val == 1 && xraycheck == 4)
        //call to tricuspid regurtation graphics
        tricregur();

}

//RESETING ALL THE VALUES TO INITIAL ARRAY
void reset()
{
    sys_wt[0] = SHD.inp_w[0], sys_wt[1] = SHD.inp_w[3],
        sys_wt[2] = SHD.inp_w[6], sys_wt[3] = SHD.inp_w[9],
        sys_wt[4] = SHD.inp_w[12], sys_wt[5] = SHD.inp_w[15],
        sys_wt[6] = BHD.inp_w[1], sys_wt[7] = BHD.inp_w[4],
        sys_wt[8] = BHD.inp_w[7], sys_wt[9] = BHD.inp_w[10],
        sys_wt[10] = BHD.inp_w[13], sys_wt[11] = BHD.inp_w[16],
        sys_wt[12] = CHD.inp_w[2], sys_wt[13] = CHD.inp_w[5],
        sys_wt[14] = CHD.inp_w[8], sys_wt[15] = CHD.inp_w[11],
        sys_wt[16] = CHD.inp_w[14], sys_wt[17] = CHD.inp_w[17],
        sys_wt[18] = echo_struct.inp_w[31], sys_wt[19] = echo_struct.inp_w[33],
        sys_wt[20] = echo_struct.inp_w[35], sys_wt[21] = echo_struct.inp_w[37],
        sys_wt[22] = echo_struct.inp_w[39], sys_wt[23] = echo_behav.inp_w[30],
        sys_wt[24] = echo_behav.inp_w[32], sys_wt[25] = echo_behav.inp_w[34],
        sys_wt[26] = echo_behav.inp_w[36], sys_wt[27] = echo_behav.inp_w[38],
        sys_wt[28] = steno.inp_w[41], sys_wt[29] = steno.inp_w[43],
        sys_wt[30] = steno.inp_w[18], sys_wt[31] = steno.inp_w[20],
        sys_wt[32] = steno.inp_w[22], sys_wt[33] = steno.inp_w[24],
        sys_wt[34] = steno.inp_w[26], sys_wt[35] = steno.inp_w[28],
        sys_wt[36] = regur.inp_w[40], sys_wt[37] = regur.inp_w[42],
        sys_wt[38] = regur.inp_w[19], sys_wt[39] = regur.inp_w[21],
        sys_wt[40] = regur.inp_w[23], sys_wt[41] = regur.inp_w[25],
        sys_wt[42] = regur.inp_w[27], sys_wt[43] = regur.inp_w[29];
}
//SAVING ALL MODIFIED WEIGHTS INTO DATA.TXT FILE
void save_file()
{
    reset();
    q = fopen("DATA2.TXT", "w");
    for (i = 0; i < 43; i++)
        fprintf(q, "%f", sys_wt[i]);
    fclose(q);
}
void read_file()
{
    q = fopen("DATA2.TXT", "r");
    for (i = 0; i < 43; i++)
        fscanf(q, "%f", &sys_wt[i]);
    fclose(q);
}

////MAIN WORKING COMPONENT--------------------

int system()
{
    if (q == NULL)
        gen_wt();
    else
        read_file();
    //struct neuron1
    SHD.th_val = threshold[0];
    SHD.working_val = 0;
    SHD.inp_w[0] = sys_wt[0];
    SHD.inp_w[1] = sys_wt[3];
    SHD.inp_w[2] = sys_wt[6];
    SHD.inp_w[3] = sys_wt[9];
    SHD.inp_w[4] = sys_wt[12];
    SHD.inp_w[5] = sys_wt[15];

    //struct neuron1
    BHD.th_val = threshold[1];
    BHD.working_val = 0;
    BHD.inp_w[0] = sys_wt[1];
    BHD.inp_w[1] = sys_wt[4];
    BHD.inp_w[2] = sys_wt[7];
    BHD.inp_w[3] = sys_wt[10];
    BHD.inp_w[4] = sys_wt[13];
    BHD.inp_w[5] = sys_wt[16];

    //struct neuron1
    CHD.th_val = threshold[2];
    CHD.working_val = 0;
    CHD.inp_w[0] = sys_wt[2];
    CHD.inp_w[1] = sys_wt[5];
    CHD.inp_w[2] = sys_wt[8];
    CHD.inp_w[3] = sys_wt[11];
    CHD.inp_w[4] = sys_wt[14];
    CHD.inp_w[5] = sys_wt[17];

    //struct neuron2
    echo_struct.th_val = threshold[3];
    echo_struct.working_val = 0;
    echo_struct.inp_w[0] = sys_wt[31];
    echo_struct.inp_w[1] = sys_wt[33];
    echo_struct.inp_w[2] = sys_wt[35];
    echo_struct.inp_w[3] = sys_wt[37];
    echo_struct.inp_w[4] = sys_wt[39];

    //struct neuron2
    echo_behav.th_val = threshold[4];
    echo_behav.working_val = 0;
    echo_behav.inp_w[0] = sys_wt[30];
    echo_behav.inp_w[1] = sys_wt[32];
    echo_behav.inp_w[2] = sys_wt[34];
    echo_behav.inp_w[3] = sys_wt[36];
    echo_behav.inp_w[4] = sys_wt[38];

    //struct neuron3
    steno.th_val = threshold[5];
    steno.working_val = 0;
    steno.inp_w[0] = sys_wt[41];
    steno.inp_w[1] = sys_wt[43];
    steno.inp_w[2] = sys_wt[18];
    steno.inp_w[3] = sys_wt[20];
    steno.inp_w[4] = sys_wt[22];
    steno.inp_w[5] = sys_wt[24];
    steno.inp_w[6] = sys_wt[26];
    steno.inp_w[7] = sys_wt[28];
    steno.outp_val = 0;

    //struct neuron3
    regur.th_val = threshold[6];
    regur.working_val = 0;
    regur.inp_w[0] = sys_wt[40];
    regur.inp_w[1] = sys_wt[42];
    regur.inp_w[2] = sys_wt[19];
    regur.inp_w[3] = sys_wt[21];
    regur.inp_w[4] = sys_wt[23];
    regur.inp_w[5] = sys_wt[25];
    regur.inp_w[6] = sys_wt[27];
    regur.inp_w[7] = sys_wt[29];
    regur.outp_val = 0;
    parse();
    final_eval();
    save_file();
    return 0;
}


/*GOING FOR ECHO-CARDIOGRAPHY IMAGES TO ECHO-CARDIOLOGY LAB*/
void echo_data()
{
    float presrg[4], prol, sv, count = 0;
    float m_mode[4], lvddi, lvddf, lvsdi, lvsdf, ivsi, ivsf, pwi, pwf, data[4];
    char c, mv;
    clrscr();
    printf("\t\tGIVE THE FOLLOWING M-MODE ECHOCARDIOGRAPHY DATA:-");
    printf("\n\t\tLEFT VENTRICULAR DIASTOLIC DIAMETER IN C.M.");
    scanf("%f", &m_mode[0]);
    printf("\n\t\tLEFT VENTRICULAR SYSTOLIC DIAMETER IN C.M.");
    scanf("%f", &m_mode[1]);
    printf("\n\t\tINTERVENTRICULAR SEPTUM SIZE IN C.M. IN DIASTOLIC STATE");
    scanf("%f", &m_mode[2]);
    printf("\n\t\tGIRTH OF POSTERIOR DIASTOLIC WALL IN C.M.");
    scanf("%f", &m_mode[3]);
    printf("\n\t\tWHAT IS YOUR GENDER?(M/F)");
    c = getch();
    if (c == 'm' || c == 'M')
    {
        lvddi = 4.3, lvddf = 5.9, lvsdi = 2.6, lvsdf = 4.0, ivsi = 0.6, ivsf = 1.3, pwi = 0.6, pwf = 1.2;
        if (m_mode[0] > lvddi && m_mode[0] <= lvddf)
            data[0] = 0;
        else data[0] = m_mode[0];
        if (m_mode[1] >= lvsdi && m_mode[1] <= lvsdf)
            data[1] = 0;
        else data[1] = m_mode[1];
        if (m_mode[2] >= ivsi && m_mode[2] <= ivsf)
            data[2] = 0;
        else data[2] = m_mode[2];
        if (m_mode[3] >= pwi && m_mode[3] <= pwf)
            data[3] = 0;
        else data[3] = m_mode[3];
        m_mode_sum = data[0] + data[1] + data[2] + data[3];//m-mode sum
    }
    else
    {
        lvddi = 4.0, lvddf = 5.2, lvsdi = 2.3, lvsdf = 3.5, ivsi = 0.5, ivsf = 1.2, pwi = 0.5, pwf = 1.1;
        if (m_mode[0] > lvddi && m_mode[0] <= lvddf)
            data[0] = 0;
        else data[0] = m_mode[0];
        if (m_mode[1] >= lvsdi && m_mode[1] <= lvsdf)
            data[1] = 0;
        else data[1] = m_mode[1];
        if (m_mode[2] >= ivsi && m_mode[2] <= ivsf)
            data[2] = 0;
        else data[2] = m_mode[2];
        if (m_mode[3] >= pwi && m_mode[3] <= pwf)
            data[3] = 0;
        else data[3] = m_mode[3];
        m_mode_sum = data[0] + data[1] + data[2] + data[3];//m-mode sum
    }
    //2 D IMAGE SCANNING
    printf("\n\t\tCHECKING THE ANATOMOCAL DEFORMITY OF POSTERIOR WALL VALVE EDGE");
    printf("\t\t1.REGULAR DEFORMED MOVEMENT ALWAYS \n\t\t2.FEXIBLE MOVEMENT OF VALVE?");
    scanf("%d", &prol);
    if (prol == 1)
        two_d[0] = 6;
    else two_d[0] = 0;
    printf("\n\t\tNORMAL OR ABNORMAL MITRAL VALVE ORIFICE??(n/a)");
    mv = getch();
    if (mv == 'n')
        two_d[1] = 0;
    else two_d[1] = 5;
    printf("\n\t\tNORMAL OR ABNORMAL STROKE VOLUME??(n/a)");
    sv = getch();
    if (sv == 'n')
        two_d[2] = 0;
    else two_d[2] = 3;
    two_dsum = two_d[0] + two_d[1] + two_d[2];// two_d sum of final input

    printf("\n\n\n\t\tOBSERVING CALCIFICATION OF AORTIC VALVE??(y/n)");
    mv = getch();
    if (mv == 'y' || mv == 'Y')
        dop_aortic = 1;
    else dop_aortic = 0;

    //TAKING VALUE OF PRESSURE GRADIENT                                         0
    printf("\n\n\t\tENTER ALL THE FOUR PRESSURE GRADIENT GOT FROM ECHO:-\n\t\tLEFT ATRICULAR PRESSURE GRADIENT(mm Hg):-");
    scanf("%d", &presrg[0]);
    if (presrg[0] >= 10 && presrg[0] <= 30)
    {
        presg_sum = presg_sum + presrg[0]; count++;
    }
    else presg_sum = presg_sum + 0;
    printf("\n\t\tLEFT VENTRICULAR PRESSURE GRADIENT:-");
    scanf("%d", &presrg[1]);
    if (presrg[1] > 100)
    {
        presg_sum = presg_sum + presrg[1]; count++;
    }
    else presg_sum = presg_sum + 0;
    printf("\n\t\tRIGHTT VENTRICULAR PRESSURE GRADIENT:-");
    scanf("%d", &presrg[3]);
    if (presrg[3] > 50)
    {
        presg_sum = presg_sum + presrg[3]; count++;
    }
    else presg_sum = presg_sum + 0;
    printf("\n\t\tRIGHT ATRIUM PRESSURE GRADIENT:-");
    scanf("%d", &presrg[2]);
    if (presrg[2] >= 8 && presrg[2] <= 18)
    {
        presg_sum = presg_sum + presrg[2]; count++;
    }
    else presg_sum = presg_sum + 0;
    presg_sum = presg_sum / count;//final pressuregradient avarage value is evaluated]

    //colour echo-image move
    printf("\n\t\tOBSERVING THE COLOR OF DEOXYGENETED AND OXYGENETED BLLOD??\n\t\t");
    printf("\n\t\t1.SOME AMOUNT MIXING OR NOT");
    printf("\n\t\t2.COMPLETE PUMPING OF BLLOD");
    scanf("%d", &color);
    system(0);
}

//TAKING DATA FROM ECG OR ELECTROCARDIOGRAM GRAPH
void echo_g()
{
    int gdriver = DETECT, gmode;
    int midx, midy, i;
    int xradius = 250, yradius = 100;
    clrscr();
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    setfillstyle(0, MAGENTA);
    fillellipse(midx, midy, xradius, yradius);
    setcolor(12);
    settextstyle(1, 0, 3);
    outtextxy(190, 220, "Go for Echocardiography ");
    delay(3000);
    closegraph();
    echo_data();
}
int ecg_data()
{
    float p1, qrs, pr, qt;
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tCALCULATE ALL REVELENT DATA FROM ECG GRAPH'S VI POINT AS:-");
    printf("\n\n\t\t\tTIME PERIOD OF P-CURVE:-");
    scanf("%f", &p1);
    printf("\n\t\t\tTIME PERIOD OF QRS-CURVE:-");
    scanf("%f", &qrs);
    printf("\n\t\t\tTIME PERIOD OF PR-CURVE:-");
    scanf("%f", &pr);
    printf("\n\t\t\tTIME PERIOD OF QT-CURVE:-");
    scanf("%f", &qt);
    ecgsum = (p1 + qrs + pr + qt) / 4;
    echo_g();
    return 0;
}
void ecg_g()
{
    int gdriver = DETECT, gmode;
    int midx, midy, i;
    int xradius = 250, yradius = 100;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    setfillstyle(0, 9);
    fillellipse(midx, midy, xradius, yradius);
    setcolor(YELLOW);
    settextstyle(1, 0, 3);
    outtextxy(190, 220, "Go for Electrocardiogram ");
    delay(2000);
    cleardevice();
    ecg_data();
}
void congestive_heart_failure()
{
    char c;
    float i;
    int d;
    printf("\n\n\nAFTER OBSERVING YOUR XRAY\t\t");
    printf("\n\n\nIT IS FOUND THAT THERE IS FLUID DEPOSITION\t\t");
    input_val[0] = 5;
    printf("\n\n\nDO YOU FEEL SHORTNESS OF BREATH ??(YES=y,NO=n)\t\t\n");
    c = getch();
    if (c == 'y')
        input_val[1] = 10;
    else
        input_val[1] = 0;
    printf("\n\nPRESS LOWER ABDOMINAL ORGANS\t\t");
    printf("\n\n\nAFTER PRESSING IS THERE ANY PERMANENT DEPRESSION ??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[2] = 5;
    else input_val[2] = 0;
    printf("\n\n\nARE YOUR ANKLES SWELLED ??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[3] = 5;
    else input_val[3] = 0;
    printf("\n\n\nHOW MUCH MAXIMUM TIME YOU CAN WORK ??\t\t");
    scanf("%f", &i);
    if (i < 1) input_val[4] = 5;
    else input_val[4] = 0;
    printf("\n\n\nWHAT IS YOUR ANGINA TYPE ??\t\t");
    printf("\n\nPRESS YOUR CHOICE\t");
    printf("\n\n1.PARASTERNAL ANGINA\t");
    printf("\n\n2.SUBASTERNAL ANGINA\t");
    printf("\n\n3.APICAL ANGINA\t");
    printf("\n\n4.EPISTERNAL ANGINA\t");
    scanf("%d", &d);
    if (d == 1)  input_val[5] = 0;
    else if (d == 2) input_val[5] = 1;
    else if (d == 3) input_val[5] = 2;
    else input_val[5] = 3;

    chf = input_val[0] + input_val[1] + input_val[2] + input_val[3] + input_val[4] + input_val[5]; //FINAL VALUE OF CONGESTIVE HEART FAILURE

}

void rheumatic_fever()
{
    char c;
    int i;
    printf("\n\n\nIS THERE ANY FUNGUS GROWTH??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[6] = 2;
    else input_val[6] = 0;
    printf("\n\n\nIS THERE ANY STREP THROAT IN FEVER??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[7] = 3;
    else input_val[7] = 0;
    printf("\n\n\nDO YOU FEEL FATIGUE IN FEVER??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[8] = 4;
    else input_val[8] = 0;
    printf("\n\n\nIS YOUR JOINTS GET SWELLED IN FEVER??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[9] = 5;
    else input_val[9] = 0;
    printf("\n\n\nDO YOU FEEL PAIN OF BODY ORGANS DURING FEVER??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[10] = 6;
    else input_val[10] = 0;
    printf("\n\n\nENTER YOUR AGE\t\t");
    scanf("%d", &i);
    if (i < 15) input_val[11] = 1;
    else input_val[11] = 2;
    rf = input_val[6] + input_val[7] + input_val[8] + input_val[9] + input_val[10] + input_val[11];//FINDING THE FINAL VALUE OF RHEUMATIC FEVER
}

void age_obstacle()
{
    int i;
    printf("\n\n\nENTER YOUR AGE\t\t");
    scanf("%d", &i);
    if (i < 15) input_val[11] = 1;
    else input_val[11] = 2;
    ao = input_val[11];//FINAL VALUE OF AGE OBSTACLE
}
void gender_obstacle()
{
    char c;
    printf("\n\n\nENTER YOUR SEX(MALE=M,FEMALE=F)\t\t");
    c = getch();
    if (c == 'm') input_val[12] = 1;
    else input_val[12] = 2;
    go = input_val[12];//FINAL VALUE OF GENDER OBSTACLE
}
//TAKING DATA FROM BLOOD REPORT
void blood_coagulogent()
{
    int i;
    printf("\n\n\nWHAT IS YOUR BLOOD GLUCOSE LEVEL IN BLOOD??\t\t");
    scanf("%d", &i);
    if (i < 80 || i>100) input_val[13] = 7;
    else input_val[13] = 0;
    printf("\n\n\nWHAT IS YOUR BLOOD CHOLESTEROL LEVEL??\t\t");
    scanf("%d", &i);
    if (i < 80 || i>180) input_val[14] = 13;
    else input_val[14] = 0;
    printf("\n\n\nWHAT IS YOUR CALCIUM CONCENTRATION IN LEG??\t\t");
    scanf("%d", &i);
    if (i < 10 || i>12) input_val[15] = 18;
    else input_val[15] = 0;
    printf("\n\n\nWHAT IS YOUR AORTIC BLOOD THROMBATIN CONCENTRATION ??\t\t");
    scanf("%d", &i);
    if (i < 1 || i>2) input_val[16] = 14;
    else input_val[16] = 0;
    bc = input_val[13] + input_val[14] + input_val[15] + input_val[16];//FINAL VALUE OF BLOOD COAGULOGENT
}

void gene_defect()
{
    char c;
    printf("\n\n\nHAVE YOU ANY CONGENTIAL HEART PROBLEM??(YES=y,NO=n)\t\t");
    c = getch();
    if (c == 'y') input_val[17] = 1;
    else input_val[17] = 0;
    gd = input_val[17];//FONAL VALUE FOR GENE DEFECT
}
void phasei()
{
    congestive_heart_failure();
    rheumatic_fever();
    age_obstacle();
    gender_obstacle();
    blood_coagulogent();
    gene_defect();
    ecg_g();
}


//TAKING DATA FROM CHEST XRAY
void chest_xray()
{
    char c;
    printf("\n\n\nOBSERVED LEFT VENTRICLE EDEMA\t\t");
    c = getch();
    if (c == 'y') xray[0] = 1;
    else xray[0] = 0;
    printf("\n\n\nOBSERVED LEFT ATRICULAR EDEMA:-\t\t");
    c = getch();
    if (c == 'y') xray[1] = 2;
    else xray[1] = 0;
    printf("\n\n\nOBSERVED RIGHT VENTRICULAR EDEMA:-\t\t");
    c = getch();
    if (c == 'y') xray[2] = 3;
    else xray[2] = 0;
    printf("\n\n\nOBSERVED RIGHT ATRIUM EDEMA:-\t\t");
    c = getch();
    if (c == 'y') xray[3] = 4;
    else xray[3] = 0;
    printf("\n\n\nOBSERVED FLUID DEPOSIT :-\t\t");
    c = getch();
    if (c == 'y') xray[4] = 5;//input_val[0]=5;
    else xray[4] = 0;
    cx = xray[0] + xray[1] + xray[2] + xray[3] + xray[5];//FINAL VALUE  OF XRAY OF CHEST
    stethoscope_sound();
}


//TAKING DATA FROM STETHOSCOPE
int stethoscope_sound()
{
    char c;
    printf("\n\n\nSOUND IS ROUGH:-\t\t");
    c = getch();
    if (c == 'y') stetho[0] = 1;
    else stetho[0] = 2;
    printf("\n\n\nSOUND IS SHORT PITCHED:-\t\t");
    c = getch();
    if (c == 'y') stetho[1] = 1;
    else stetho[1] = 2;
    printf("\n\n\n SOUND IS FOR LONGER PERIOD:-\t\t");
    c = getch();
    if (c == 'y') stetho[2] = 1;
    else stetho[2] = 2;
    mv1 = stetho[0] + stetho[1] + stetho[2]; //FINAL VALUE OF HEART MURMUR
    phasei();
    return 0;
}

void prescribe()
{
    int gdriver = DETECT, gmode;
    int midx, midy, i;
    int xradius = 300, yradius = 150;
    int xradius1 = 180, yradius1 = 100;
    clrscr();
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    setfillstyle(1, BLUE);
    fillellipse(midx, midy, xradius, yradius);
    setcolor(YELLOW);
    settextstyle(1, 0, 3);
    outtextxy(80, 200, " You Are Prescribed To Go for The Tests");
    delay(5000);
    cleardevice();
    setfillstyle(0, BLUE);
    fillellipse(midx, midy, xradius1, yradius1);
    setcolor(WHITE);
    settextstyle(1, 0, 3);
    outtextxy(240, 220, "Go for x-rays ");
    delay(3000);
    cleardevice();
    chest_xray();
}
void no_disease()
{
    int gdriver = DETECT, gmode;
    int midx, midy, i;
    int xradius = 250, yradius = 150;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    setfillstyle(1, GREEN);
    fillellipse(midx, midy, xradius, yradius);
    setcolor(RED);
    settextstyle(3, 0, 5);
    outtextxy(280, 130, "No");
    outtextxy(110, 180, "Heart Related Disease");
    outtextxy(250, 230, "Found");
    line(180, 320, 440, 320);
    line(180, 325, 440, 325);
    getch();
}

void set_heart()
{
    if (count_heart == 0)
    {
        w[0] = 10, w[1] = 10, w[3] = 10, w[9] = 6;
        count_heart++;
    }
    if (count_heart == 1)
    {
        w[0] = 12, w[1] = 14, w[3] = 12, w[9] = 8;
        count_heart++;
    }
    if (count_heart == 2)
    {
        w[0] = 14, w[1] = 16, w[3] = 11, w[9] = 9;
        count_heart++;
    }
}
void set_body()
{
    if (count_body == 0)
    {
        w[2] = 3, w[7] = 2, w[10] = 4, w[11] = 8, w[12] = 2, w[13] = 3;
        count_body++;
    }
    if (count_body == 1)
    {
        w[2] = 4, w[7] = 2, w[10] = 1, w[11] = 1, w[12] = 2, w[13] = 2;
        count_body++;
    }
    if (count_body == 2)
    {
        w[2] = 4, w[7] = 1, w[10] = 1, w[11] = 1, w[12] = 2, w[13] = 1;
        count_body++;
    }
}

void data_for_observation()
{
    int i, inn[14], sum[3], wh[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
    , wb[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, wbd[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    char c;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");

    //SETTING OR INITIALIZING THE WEIGHTS OF THIS NEURAL NETWORK
    for (i = 0; i < 14; i++)
        w[i] = (1 + random(15));
    wh[0] = w[0], wh[1] = w[1], wh[3] = w[3], wh[9] = w[9];
    wb[4] = w[4], wb[5] = w[5], wb[6] = w[6], wb[8] = w[8];
    wbd[3] = w[3], wbd[7] = w[7], wbd[10] = w[10], wbd[11] = w[11], wbd[12] = w[12], wbd[13] = w[13];
    clrscr();
    cleardevice();

    //ASKING QUESTIONS TO THE PATIENT FOR OBSERVATION

    setbkcolor(BLUE);
    setfillstyle(1, 0);
    bar(60, 60, (getmaxx() - 60), (getmaxy() - 60));
    setfillstyle(1, 6);
    bar(65, 65, (getmaxx() - 65), (getmaxy() - 65));
    settextstyle(7, 0, 3);
    outtextxy(100, 200, "GIVE ALL ANSWER IN YES AND NO");
    settextstyle(2, 0, 8);
    outtextxy(150, 250, "YES=y AND NO=ANY KEY");
    delay(5000);
    cleardevice();
    setbkcolor(BLUE);

    printf("\n\n\n\n\n\n\n\n\n\n\t\tDO TOU HAVE BLOOD PRESSURE?");
    c = getch();
    c = getch();
    if (c == 'y')
        inn[0] = 1; else inn[0] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tIS YOUR PULSE RATE IS LOW?(BY CHECK)");
    c = getch();
    if (c == 'y')
        inn[1] = 1; else inn[1] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tARE YOU FEELING UNCOMFORTABLE DURING EXTRA WORK?");
    c = getch();
    if (c == 'y')
        inn[2] = 1; else inn[2] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tHAVE YOU EVER FELT CHEST PAIN?");
    c = getch();
    if (c == 'y')
        inn[3] = 1; else inn[3] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tARE YOU REGULARLY/IRREGULARLY LOSING CONSCIOUSNESS?");
    c = getch();
    if (c == 'y')
        inn[4] = 1; else inn[4] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tARE YOU FEELING DIZZINESS OR GETING ANNOY REGULARLY?");
    c = getch();
    if (c == 'y')
        inn[5] = 1; else inn[5] = 0;
    clrscr();

    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tARE YOU EVER FEELING HEADACHE?");
    c = getch();
    if (c == 'y')
        inn[6] = 1; else inn[6] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tHAVE YOU EVER FELT RINGING OF EAR?");
    c = getch();
    if (c == 'y')
        inn[7] = 1; else inn[7] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\t\tDO YOU HAVE ANY MEMORY PROBLEM?");
    c = getch();
    if (c == 'y')
        inn[8] = 1; else inn[8] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tOBSERVE NODDING OF HEAD DURING HEART BEAT?");
    c = getch();
    if (c == 'y')
        inn[9] = 1; else inn[9] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\tIS ANY PART OF YOUR BODY GET SWELLED(ABDOMEN/ANKLE/FEET etc)?");
    c = getch();
    if (c == 'y')
        inn[10] = 1; else inn[10] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tOBSERVED ANY THORAT INFECTION?");
    c = getch();
    if (c == 'y')
        inn[11] = 1; else inn[11] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tDO YOU FEELING YOUR URINE AMOUNT IS LESS AT URINATION?");
    c = getch();
    if (c == 'y')
        inn[12] = 1; else inn[12] = 0;
    clrscr();
    cleardevice();
    printf("\n\n\n\n\n\n\n\n\n\n\t\tDO YOUR BODY PART GETTING FATIGUED OR TIRED?");
    c = getch();
    if (c == 'y')
        inn[13] = 1; else inn[13] = 0;

    //ADDING ALL HEART NODE'S COMPONENT

    if (((wh[0] * inn[0]) + (wh[1] * inn[1]) + (wh[2] * inn[2]) + (wh[3] * inn[3])
        + (wh[4] * inn[4]) + (wh[5] * inn[5]) + (wh[6] * inn[6]) +
        (wh[7] * inn[7]) + (wh[8] * inn[8]) + (wh[9] * inn[9])
        + (wh[10] * inn[10]) + (wh[11] * inn[11]) + (wh[12] * inn[12])
        + (wh[13] * inn[13])) == t[0])
    {
        count_heart = 3;
        sum[0] = t[0];
    }
    else
    {
        if ((inn[0] + inn[1] + inn[3] + inn[9]) == 0)
            no_disease();
        // else part going to working part
        prescribe();
    }

    sum[1] = t[1];

    if (((wbd[0] * inn[0]) + (wbd[1] * inn[1]) + (wbd[2] * inn[2]) + (wbd[3] * inn[3])
        + (wbd[4] * inn[4]) + (wbd[5] * inn[5]) + (wbd[6] * inn[6]) +
        (wbd[7] * inn[7]) + (wbd[8] * inn[8]) + (wbd[9] * inn[9])
        + (wbd[10] * inn[10]) + (wbd[11] * inn[11]) + (wbd[12] * inn[12])
        + (wbd[13] * inn[13])) == t[2])
    {
        count_body = 3;
        sum[2] = t[2];
    }
    else
        set_body();
    getch();
}
//INITIAL WINDOW TO ENTER INTO THE PROGRAM...

int start_menu()
{
    int gdriver = DETECT, gmode, mx, my, i, branch;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    cleardevice();
    setcolor(7);
    mx = getmaxx();
    my = getmaxy();
    for (i = 0; i < 10; i++)
    {
        rectangle(i, i, mx - i, my - i);
    }
    setcolor(12);
    settextstyle(4, 0, 4);
    outtextxy(180, 80, "...MAIN  MENU...");
    settextstyle(1, 0, 3); setcolor(8);
    line(10, 120, 629, 120);
    line(10, 122, 629, 122);
    line(10, 124, 629, 124); setcolor(YELLOW);
    outtextxy(100, 200, "1.New Patient's Diagnosis");
    outtextxy(100, 230, "2.Exit From The System");
    setcolor(BLUE);
    settextstyle(5, 0, 4);
    outtextxy(0, 420, "   Choose your choice And Press Enter:-");
    scanf("%d", &branch);
    if (branch == 1)
        data_for_observation();
    else
        exit(0);
    return 0;
}
void success()
{
    int i, j, k;
    int gdriver = DETECT, gmode, maxx, maxy;
    initgraph(&gdriver, &gmode, "\\tc\\bgi"); //INITIALIZES THE GRAPHICS DRIVER
    maxx = getmaxx(), maxy = getmaxy();
    cleardevice();
    setcolor(10);
    rectangle(50, 50, maxx - 50, maxy - 50);
    setcolor(13);
    rectangle(55, 55, maxx - 55, maxy - 55);
    setfillstyle(10, 3);
    bar(56, 56, maxx - 56, maxy - 56);
    setcolor(11);
    settextstyle(3, 0, 2);
    outtextxy(70, 150, "ALL COMPONENTS ARE SUCCESSFULLY CONNECTED..");
    settextstyle(6, 0, 2);
    setcolor(4);
    setlinestyle(2, 5, 6);
    line(160, 190, maxx - 160, 190);
    setcolor(5);
    outtextxy(180, 330, "WAIT FOR 5 SECONDs......");
    delay(5000);
    start_menu();
}
void sound_processing()
{
    int i, j, k;
    int gdriver = DETECT, gmode, maxx, maxy;
    initgraph(&gdriver, &gmode, "\\tc\\bgi"); //INITIALIZES THE GRAPHICS DRIVER
    maxx = getmaxx(), maxy = getmaxy();
    cleardevice();
    setcolor(10);
    rectangle(50, 50, maxx - 50, maxy - 50);
    setcolor(13);
    rectangle(55, 55, maxx - 55, maxy - 55);
    setfillstyle(10, 3);
    bar(56, 56, maxx - 56, maxy - 56);
    setcolor(14);
    settextstyle(7, 0, 5);
    outtextxy(180, 200, "PROCESSING");
    settextstyle(10, 0, 5);
    setcolor(6);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 2; j++)
        {
            outtextxy(160 + (i * 20), 200, ".");
            sound(j * 1000);
            delay(500);
            nosound();
        }
    }
    success();
}
//FIRST WELCOME SCREEN IS TO PRINT
void welcome()
{
    int gdriver = DETECT, gmode, maxx, maxy, i, j, k;
    char a[60];
    initgraph(&gdriver, &gmode, "\\tc\\bgi"); //INITIALIZES THE GRAPHICS DRIVER
    maxx = getmaxx(), maxy = getmaxy();
    cleardevice();
    setcolor(10);
    rectangle(50, 50, maxx - 50, maxy - 50);
    setcolor(13);
    rectangle(55, 55, maxx - 55, maxy - 55);
    setfillstyle(6, 8);
    bar(56, 56, maxx - 56, maxy - 56);
    setcolor(10);
    settextstyle(10, 0, 5);
    outtextxy(120, 100, "..WELCOME..");
    setcolor(4);
    setlinestyle(1, 5, 3);
    line(60, 200, maxx - 60, 200);
    setcolor(9);
    settextstyle(4, 0, 4);
    outtextxy(280, 220, "TO");
    setcolor(11);
    settextstyle(2, 0, 8);
    outtextxy(80, 270, "HEART DISEASE RECOGNITION SYSTEM");

    //INSERTING SOUND TO THE SCREEN

    for (k = 0; k < 20; k++)
    {
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 10; j++)
            {
                sound(i * 800);
                delay(5);
            }
            nosound();
        }
    }
    sound_processing();
}
//SETTING A PASSWORD FOR OPENING THIS PROGRAMM
void connect()
{
    int d = DETECT, gmode, i;
    char user[100], a[10];
    initgraph(&d, &gmode, "\\tc\\bgi");
    cleardevice();
    printf("\n\n\n\n\n\n\n\t\t\tEnter user name:-");
    scanf("%s", user);
    printf("\n\n\n\n\n\t\t\tPASSWORD:-");
    textcolor(0);
    cscanf("%s", a);
    i = stricmp(p, a);
    if (i == 0)
        welcome();
    else
        exit(0);
}

void main()
{
    clrscr();
    connect();
    getch();
}
