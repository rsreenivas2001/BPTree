#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

class Song
{
public:
    string name;
    string artist_name;
    string album_name;
    string genre_name;
    string playlist_name1;
    string playlist_name2;
    string playlist_name3;
    LPCSTR url;
    Song *artist;
    Song *album;
    Song *genre;
    Song *playlist1;
    Song *playlist2;
    Song *playlist3;
    Song *playlist4;
    Song *playlist5;
    Song *custom;
};

Song *art[15],*gen[6],*play[5],*alb[68],*cus;

void initialize()
{
    int x;
    for(x=0;x<15;x++)
    {
        art[x]=NULL;
    }
    for(x=0;x<6;x++)
    {
        gen[x]=NULL;
    }
    for(x=0;x<5;x++)
    {
        play[x]=NULL;
    }
    for(x=0;x<68;x++)
    {
        alb[x]=NULL;
    }
    cus=NULL;
}

int main()
{
    int i;
    Song Tracks[113];
    string list[68];
    LPCSTR verb="open";

    list[0]="MASTER";
    list[1]="SOORARAI POTTRU";
    list[2]="KANNUM KANNUM KOLLAIYADITHAL";
    list[3]="OH MY KADAVULE";
    list[4]="DHARALA PRABHU";
    list[5]="NAAN SIRITHAAL";
    list[6]="PATTAS";
    list[7]="HERO";
    list[8]="ADITHYA VARMA";
    list[9]="PSYCHO";
    list[10]="RAJA RANI";
    list[11]="TEDDY";
    list[12]="DEEPAVALI";
    list[13]="VAARANAM AAYIRAM";
    list[14]="KADAL";
    list[15]="MEESAYA MURUKKU";
    list[16]="GULEBAGAVALI";
    list[17]="VANAKKAM CHENNAI";
    list[18]="MEYAADHA MAAN";
    list[19]="PAIYA";
    list[20]="ENGEYUM KADHAL";
    list[21]="KAATRIN MOZHI";
    list[22]="IMAIKKA NODIGAL";
    list[23]="THREE";
    list[24]="MIRUTHAN";
    list[25]="GOA";
    list[26]="ANEGAN";
    list[27]="RAAVANAN";
    list[28]="ROMEO JULIET";
    list[29]="MANMADHAN";
    list[30]="MR.LOCAL";
    list[31]="VINNAI THAANDI VARUVAYA";
    list[32]="I";
    list[33]="REMO";
    list[34]="OK OK";
    list[35]="YAARADI NEE MOHINI";
    list[36]="BIGIL";
    list[37]="SILLUNU ORU KADHAL";
    list[38]="ENAI NOKKI PAAYUM THOTA";
    list[39]="DARLING";
    list[40]="MAAN KARATE";
    list[41]="PYAR PREMA KAADHAL";
    list[42]="KANAA";
    list[43]="THNAGAMAGAN";
    list[44]="KABALI";
    list[45]="AADUKALAM";
    list[46]="PETTA";
    list[47]="COMALI";
    list[48]="THAANA SERNDHA KOOTAM";
    list[49]="VEDHALAM";
    list[50]="ETHIR NEECHAL";
    list[51]="MADARASAPATTINAM";
    list[52]="VISWASAM";
    list[53]="MERSAL";
    list[54]="24";
    list[55]="VIKRAM VEDHA";
    list[56]="SIVAPU MANJAL PACHAI";
    list[57]="NAANUM ROWDY THAAN";
    list[58]="NGK";
    list[59]="MAARI 2";
    list[60]="MARYAN";
    list[61]="RAJINI MURUGAN";
    list[62]="NATPE THUNAI";
    list[63]="MAARI";
    list[64]="VIP";
    list[65]="VELAIKARAN";
    list[66]="MANKATHA";
    list[67]="BIRIYANI";

    Tracks[0].name="VAATHI COMING";
    Tracks[0].artist_name="ANIRUDH RAVICHANDER";
    Tracks[0].album_name="MASTER";
    Tracks[0].genre_name="PARTY";
    Tracks[0].playlist_name1="LATEST TAMIL";
    Tracks[0].playlist_name2="PARTY TONIGHT";
    Tracks[0].url="https://www.youtube.com/watch?v=vxzfsBDx590";

    Tracks[1].name="ANDHA KANNA PAATHAKA";
    Tracks[1].artist_name="ANIRUDH RAVICHANDER";
    Tracks[1].album_name="MASTER";
    Tracks[1].genre_name="MELODY";
    Tracks[1].playlist_name1="LATEST TAMIL";
    Tracks[1].url="https://www.youtube.com/watch?v=3hVc3M1IEe0";

    Tracks[2].name="VEYYON SILLI";
    Tracks[2].artist_name="G.V.PRAKASH KUMAR";
    Tracks[2].album_name="SOORARAI POTTRU";
    Tracks[2].genre_name="LOVE";
    Tracks[2].playlist_name1="LATEST TAMIL";
    Tracks[2].url="https://www.youtube.com/watch?v=0f_ho4Wem0w";

    Tracks[3].name="KUTTI STORY";
    Tracks[3].artist_name="ANIRUDH RAVICHANDER";
    Tracks[3].album_name="MASTER";
    Tracks[3].genre_name="MOOD";
    Tracks[3].playlist_name1="LATEST TAMIL";
    Tracks[3].url="https://www.youtube.com/watch?v=gjnrtCKZqYg";

    Tracks[4].name="SIRIKKALAM PARAKKALAM";
    Tracks[4].artist_name="BENNY DAYAL";
    Tracks[4].album_name="KANNUM KANNUM KOLLAIYADITHAL";
    Tracks[4].genre_name="PARTY";
    Tracks[4].playlist_name1="LATEST TAMIL";
    Tracks[4].url="https://www.youtube.com/watch?v=vlYv7Ri-GQU";

    Tracks[5].name="YELO PULLELO";
    Tracks[5].artist_name="ANIRUDH RAVICHANDER";
    Tracks[5].album_name="KANNUM KANNUM KOLLAIYADITHAL";
    Tracks[5].genre_name="PARTY";
    Tracks[5].playlist_name1="LATEST TAMIL";
    Tracks[5].url="https://www.youtube.com/watch?v=nfH0pa0VSBI";

    Tracks[6].name="VAATHI RAID";
    Tracks[6].artist_name="ANIRUDH RAVICHANDER";
    Tracks[6].album_name="MASTER";
    Tracks[6].genre_name="RAP";
    Tracks[6].playlist_name1="LATEST TAMIL";
    Tracks[6].url="https://www.youtube.com/watch?v=eHoIUNY-bG4";

    Tracks[7].name="MANNURUNDA";
    Tracks[7].artist_name="G.V.PRAKASH KUMAR";
    Tracks[7].album_name="SOORARAI POTTRU";
    Tracks[7].genre_name="FOLK";
    Tracks[7].playlist_name1="LATEST TAMIL";
    Tracks[7].url="https://www.youtube.com/watch?v=KDlkS6l2ZTU";

    Tracks[8].name="KADHAIPOMA";
    Tracks[8].artist_name="LEON JAMES";
    Tracks[8].album_name="OH MY KADAVULE";
    Tracks[8].genre_name="MELODY";
    Tracks[8].playlist_name1="LATEST TAMIL";
    Tracks[8].url="https://www.youtube.com/watch?v=DScFlfN9vDk";

    Tracks[9].name="KAADHAL THEEVEY";
    Tracks[9].artist_name="SID SRIRAM";
    Tracks[9].album_name="DHARALA PRABHU";
    Tracks[9].genre_name="MELODY";
    Tracks[9].playlist_name1="LATEST TAMIL";
    Tracks[9].url="https://www.youtube.com/watch?v=NGkEwWewgmY";

    Tracks[10].name="BREAKUP SONG";
    Tracks[10].artist_name="HIP HOP THAMIZHA";
    Tracks[10].album_name="NAAN SIRITHAAL";
    Tracks[10].genre_name="PARTY";
    Tracks[10].playlist_name1="LATEST TAMIL";
    Tracks[10].playlist_name2="HEART BREAKERS";
    Tracks[10].playlist_name3="PARTY TONIGHT";
    Tracks[10].url="https://www.youtube.com/watch?v=lxROTQJEB58";

    Tracks[11].name="HAIYO HAIYO";
    Tracks[11].artist_name="LEON JAMES";
    Tracks[11].album_name="OH MY KADAVULE";
    Tracks[11].genre_name="LOVE";
    Tracks[11].playlist_name1="LATEST TAMIL";
    Tracks[11].url="https://www.youtube.com/watch?v=lJXDFmqr564";

    Tracks[12].name="AJUKKU GUMUKKU";
    Tracks[12].artist_name="HIP HOP THAMIZHA";
    Tracks[12].album_name="NAAN SIRITHAAL";
    Tracks[12].genre_name="FOLK";
    Tracks[12].playlist_name1="LATEST TAMIL";
    Tracks[12].url="https://www.youtube.com/watch?v=ji55jouN_8k";

    Tracks[13].name="CHILL BRO";
    Tracks[13].artist_name="DHANUSH";
    Tracks[13].album_name="PATTAS";
    Tracks[13].genre_name="PARTY";
    Tracks[13].playlist_name1="LATEST TAMIL";
    Tracks[13].playlist_name2="PARTY TONIGHT";
    Tracks[14].url="https://www.youtube.com/watch?v=pHxz8l1iWU4";

    Tracks[14].name="NAAN SIRICHA";
    Tracks[14].artist_name="HIP HOP THAMIZHA";
    Tracks[14].album_name="NAAN SIRITHAAL";
    Tracks[14].genre_name="PARTY";
    Tracks[14].playlist_name1="LATEST TAMIL";
    Tracks[14].url="https://www.youtube.com/watch?v=Ckwj8Xsil88";

    Tracks[15].name="JIGIDI KILLADI";
    Tracks[15].artist_name="ANIRUDH RAVICHANDER";
    Tracks[15].album_name="PATTAS";
    Tracks[15].genre_name="LOVE";
    Tracks[15].playlist_name1="LATEST TAMIL";
    Tracks[15].url="https://www.youtube.com/watch?v=v7RwLCdx-AI";

    Tracks[16].name="OVERA FEEL PANNUREN";
    Tracks[16].artist_name="YUVAN SHANKAR RAJA";
    Tracks[16].album_name="HERO";
    Tracks[16].genre_name="LOVE";
    Tracks[16].playlist_name1="LATEST TAMIL";
    Tracks[16].url="https://www.youtube.com/watch?v=kBHstSYCgew";

    Tracks[17].name="DHOM DHOM";
    Tracks[17].artist_name="HIP HOP THAMIZHA";
    Tracks[17].album_name="NAAN SIRITHAAL";
    Tracks[17].genre_name="MELODY";
    Tracks[17].playlist_name1="LATEST TAMIL";
    Tracks[17].url="https://www.youtube.com/watch?v=29FUG72LVFE";

    Tracks[18].name="YEAN ENNAI PIRINDHAAI";
    Tracks[18].artist_name="SID SRIRAM";
    Tracks[18].album_name="ADITHYA VARMA";
    Tracks[18].genre_name="MELODY";
    Tracks[18].playlist_name1="LATEST TAMIL";
    Tracks[18].playlist_name2="HEART BREAKERS";
    Tracks[18].url="https://www.youtube.com/watch?v=9pWrJM5nkl4";

    Tracks[19].name="UNNA NENACHU";
    Tracks[19].artist_name="SID SRIRAM";
    Tracks[19].album_name="PSYCHO";
    Tracks[19].genre_name="MELODY";
    Tracks[19].playlist_name1="LATEST TAMIL";
    Tracks[19].playlist_name2="HEART BREAKERS";
    Tracks[19].playlist_name3="ROMANTIC ACOUSTICS";
    Tracks[19].url="https://www.youtube.com/watch?v=jFWsj_QT0G8";

    Tracks[20].name="MALTO KITHAPULEH";
    Tracks[20].artist_name="YUVAN SHANKAR RAJA";
    Tracks[20].album_name="HERO";
    Tracks[20].genre_name="PARTY";
    Tracks[20].playlist_name1="LATEST TAMIL";
    Tracks[20].url="https://www.youtube.com/watch?v=NHzwno5Y2XA";

    Tracks[21].name="QUIT PANNUDA";
    Tracks[21].artist_name="ANIRUDH RAVICHANDER";
    Tracks[21].album_name="MASTER";
    Tracks[21].genre_name="MELODY";
    Tracks[21].playlist_name1="LATEST TAMIL";
    Tracks[21].url="https://www.youtube.com/watch?v=fccXKFiXEGU";

    Tracks[22].name="POLAKATUM PARA PARA";
    Tracks[22].artist_name="SANTHOSH NARAYANAN";
    Tracks[22].album_name="MASTER";
    Tracks[22].genre_name="FOLK";
    Tracks[22].playlist_name1="LATEST TAMIL";
    Tracks[22].url="https://www.youtube.com/watch?v=dZN4TD9Ane0";

    Tracks[23].name="EDHARKADI";
    Tracks[23].artist_name="DHRUV VIKRAM";
    Tracks[23].album_name="ADITHYA VARMA";
    Tracks[23].genre_name="LOVE";
    Tracks[23].playlist_name1="HEART BREAKERS";
    Tracks[23].url="https://www.youtube.com/watch?v=Y1JCAXAxoMg";

    Tracks[24].name="IMAYE IMAYE";
    Tracks[24].artist_name="G.V.PRAKASH KUMAR";
    Tracks[24].album_name="RAJA RANI";
    Tracks[24].genre_name="MELODY";
    Tracks[24].playlist_name1="HEART BREAKERS";
    Tracks[24].url="https://www.youtube.com/watch?v=d38xWWg62LY";

    Tracks[25].name="MARANDHAYE";
    Tracks[25].artist_name="D.IMMAN";
    Tracks[25].album_name="TEDDY";
    Tracks[25].genre_name="MELODY";
    Tracks[25].playlist_name1="HEART BREAKERS";
    Tracks[25].url="https://www.youtube.com/watch?v=gIDG3cd_I7I";

    Tracks[26].name="POGADHE";
    Tracks[26].artist_name="YUVAN SHANKAR RAJA";
    Tracks[26].album_name="DEEPAVALI";
    Tracks[26].genre_name="MELODY";
    Tracks[26].playlist_name1="HEART BREAKERS";
    Tracks[26].url="https://www.youtube.com/watch?v=ujV-0AT60pU";

    Tracks[27].name="AVA ENNA";
    Tracks[27].artist_name="HARRIS JAYARAJ";
    Tracks[27].album_name="VAARANAM AAYIRAM";
    Tracks[27].genre_name="FOLK";
    Tracks[27].playlist_name1="HEART BREAKERS";
    Tracks[27].url="https://www.youtube.com/watch?v=5yjy7djTUDc";

    Tracks[28].name="MOONGIL THOTTAM";
    Tracks[28].artist_name="A.R.RAHMAN";
    Tracks[28].album_name="KADAL";
    Tracks[28].genre_name="MELODY";
    Tracks[28].playlist_name1="HEART BREAKERS";
    Tracks[28].playlist_name2="ROMANTIC ACOUSTICS";
    Tracks[28].playlist_name3="INIYA IRAVU";
    Tracks[28].url="https://www.youtube.com/watch?v=EQ783EHQkng";

    Tracks[29].name="VAADI PULLA VAADI";
    Tracks[29].artist_name="HIP HOP THAMIZHA";
    Tracks[29].album_name="MEESAYA MURUKKU";
    Tracks[29].genre_name="LOVE";
    Tracks[29].playlist_name1="HEART BREAKERS";
    Tracks[29].url="https://www.youtube.com/watch?v=7mWd8fOG7qI";

    Tracks[30].name="SERAMAL PONAL";
    Tracks[30].artist_name="VIVEK-MERVIN";
    Tracks[30].album_name="GULEBAGAVALI";
    Tracks[30].genre_name="MELODY";
    Tracks[30].playlist_name1="HEART BREAKERS";
    Tracks[30].playlist_name2="INIYA IRAVU";
    Tracks[30].url="https://www.youtube.com/watch?v=URgqLY3Z7PQ";

    Tracks[31].name="OH PENNE";
    Tracks[31].artist_name="ANIRUDH RAVICHANDER";
    Tracks[31].album_name="VANAKKAM CHENNAI";
    Tracks[31].genre_name="MELODY";
    Tracks[31].playlist_name1="HEART BREAKERS";
    Tracks[31].playlist_name2="INIYA IRAVU";
    Tracks[31].url="https://www.youtube.com/watch?v=C7MAqIcM-Sg";

    Tracks[32].name="MEGAMO AVAL";
    Tracks[32].artist_name="SANTHOSH NARAYANAN";
    Tracks[32].album_name="MEYAADHA MAAN";
    Tracks[32].genre_name="MELODY";
    Tracks[32].playlist_name1="HEART BREAKERS";
    Tracks[32].url="https://www.youtube.com/watch?v=mVubYBRajfw";

    Tracks[33].name="YEDHO ONDRU ENNAI";
    Tracks[33].artist_name="YUVAN SHANKAR RAJA";
    Tracks[33].album_name="PAIYA";
    Tracks[33].genre_name="LOVE";
    Tracks[33].playlist_name1="HEART BREAKERS";
    Tracks[33].url="https://www.youtube.com/watch?v=UeYP7909Ovg";

    Tracks[34].name="DHIMU DHIMU";
    Tracks[34].artist_name="HARRIS JAYARAJ";
    Tracks[34].album_name="ENGEYUM KADHAL";
    Tracks[34].genre_name="MELODY";
    Tracks[34].playlist_name1="HEART BREAKERS";
    Tracks[34].url="https://www.youtube.com/watch?v=QoK8x_2C4go";

    Tracks[35].name="PO URAVE";
    Tracks[35].artist_name="SID SRIRAM";
    Tracks[35].album_name="KAATRIN MOZHI";
    Tracks[35].genre_name="MOOD";
    Tracks[35].playlist_name1="HEART BREAKERS";
    Tracks[35].url="https://www.youtube.com/watch?v=JdVPh0vu2zI";

    Tracks[36].name="MANNIPAAYA";
    Tracks[36].artist_name="A.R.RAHMAN";
    Tracks[36].album_name="VINNAI THAANDI VARUVAYAA";
    Tracks[36].genre_name="MELODY";
    Tracks[36].playlist_name1="HEART BREAKERS";
    Tracks[36].url="https://www.youtube.com/watch?v=EjUP08N89mI";

    Tracks[37].name="KADHAL ORU AAGAYAM";
    Tracks[37].artist_name="HIP HOP THAMIZHA";
    Tracks[37].album_name="IMAIKKA NODIGAL";
    Tracks[37].genre_name="MELODY";
    Tracks[37].playlist_name1="HEART BREAKERS";
    Tracks[37].url="https://www.youtube.com/watch?v=kmhrT7fPYO4";

    Tracks[38].name="PO NEE PO";
    Tracks[38].artist_name="ANIRUDH RAVICHANDER";
    Tracks[38].album_name="THREE";
    Tracks[38].genre_name="LOVE";
    Tracks[38].playlist_name1="HEART BREAKERS";
    Tracks[38].url="https://www.youtube.com/watch?v=DnyA_qEbTpw";

    Tracks[39].name="MUNNAL KADHALI";
    Tracks[39].artist_name="D.IMMAN";
    Tracks[39].album_name="MIRUTHAN";
    Tracks[39].genre_name="MOOD";
    Tracks[39].playlist_name1="HEART BREAKERS";
    Tracks[39].url="https://www.youtube.com/watch?v=q4u4zIbhkdI";

    Tracks[40].name="KAADHAL ENDRAL";
    Tracks[40].artist_name="YUVAN SHANKAR RAJA";
    Tracks[40].album_name="GOA";
    Tracks[40].genre_name="LOVE";
    Tracks[40].playlist_name1="HEART BREAKERS";
    Tracks[40].url="https://www.youtube.com/watch?v=dfGpFJW9GHY";

    Tracks[41].name="THODU VAANAM";
    Tracks[41].artist_name="HARRIS JAYARAJ";
    Tracks[41].album_name="ANEGAN";
    Tracks[41].genre_name="MOOD";
    Tracks[41].playlist_name1="HEART BREAKERS";
    Tracks[41].url="https://www.youtube.com/watch?v=vSYI6ZrkE80";

    Tracks[42].name="USURE POGUDHEY";
    Tracks[42].artist_name="A.R.RAHMAN";
    Tracks[42].album_name="RAAVANAN";
    Tracks[42].genre_name="MELODY";
    Tracks[42].playlist_name1="HEART BREAKERS";
    Tracks[42].url="https://www.youtube.com/watch?v=yCKO5KUDcVs";

    Tracks[43].name="THOOVANAM";
    Tracks[43].artist_name="D.IMMAN";
    Tracks[43].album_name="ROMEO JULIET";
    Tracks[43].genre_name="LOVE";
    Tracks[43].playlist_name1="HEART BREAKERS";
    Tracks[43].url="https://www.youtube.com/watch?v=K9jQm0FZZ98";

    Tracks[44].name="KADHAL VALARTHEN";
    Tracks[44].artist_name="YUVAN SHANKAR RAJA";
    Tracks[44].album_name="MANMADHAN";
    Tracks[44].genre_name="MOOD";
    Tracks[44].playlist_name1="HEART BREAKERS";
    Tracks[44].url="https://www.youtube.com/watch?v=ALDVhVPnjus";

    Tracks[45].name="NEE NENACHA";
    Tracks[45].artist_name="SID SRIRAM";
    Tracks[45].album_name="MR.LOCAL";
    Tracks[45].genre_name="MOOD";
    Tracks[45].playlist_name1="HEART BREAKERS";
    Tracks[45].url="https://www.youtube.com/watch?v=HUwEXHPEgdM";

    Tracks[46].name="AAROMALE";
    Tracks[46].artist_name="A.R.RAHMAN";
    Tracks[46].album_name="VINNAI THAANDI VARUVAAYA";
    Tracks[46].genre_name="MOOD";
    Tracks[46].playlist_name1="HEART BREAKERS";
    Tracks[46].url="https://www.youtube.com/watch?v=q7OUFE3dw6E";

    Tracks[47].name="ENNODU NEE IRUNTHAL";
    Tracks[47].artist_name="A.R.RAHMAN";
    Tracks[47].album_name="I";
    Tracks[47].genre_name="MELODY";
    Tracks[47].playlist_name1="HEART BREAKERS";
    Tracks[47].playlist_name2="ROMANTIC ACOUSTICS";
    Tracks[47].url="https://www.youtube.com/watch?v=EhhiY11Z9-U";

    Tracks[48].name="DAAVUYA";
    Tracks[48].artist_name="SANTHOSH NARAYANAN";
    Tracks[48].album_name="REMO";
    Tracks[48].genre_name="PARTY";
    Tracks[48].playlist_name1="HEART BREAKERS";
    Tracks[48].playlist_name2="PARTY TONIGHT";
    Tracks[48].url="https://www.youtube.com/watch?v=GRKyx31fqjE";

    Tracks[49].name="VENAAM MACHAN";
    Tracks[49].artist_name="HARRIS JAYARAJ";
    Tracks[49].album_name="OK OK";
    Tracks[49].genre_name="FOLK";
    Tracks[49].playlist_name1="HEART BREAKERS";
    Tracks[49].url="https://www.youtube.com/watch?v=Q_RiJmvmcyQ";

    Tracks[50].name="VENMEGAM";
    Tracks[50].artist_name="YUVAN SHANKAR RAJA";
    Tracks[50].album_name="YAARADI NEE MOHINI";
    Tracks[50].genre_name="MELODY";
    Tracks[50].playlist_name1="HEART BREAKERS";
    Tracks[50].url="https://www.youtube.com/watch?v=JzTNs0gY_ZU";

    Tracks[51].name="ADIYAE IVALEY";
    Tracks[51].artist_name="D.IMMAN";
    Tracks[51].album_name="ROMEO JULIET";
    Tracks[51].genre_name="FOLK";
    Tracks[51].playlist_name1="HEART BREAKERS";
    Tracks[51].playlist_name2="PARTY TONIGHT";
    Tracks[51].url="https://www.youtube.com/watch?v=E55QqxWUYk8";

    Tracks[52].name="WHY THIS KOLAVERI DI";
    Tracks[52].artist_name="DHANUSH";
    Tracks[52].album_name="THREE";
    Tracks[52].genre_name="PARTY";
    Tracks[52].playlist_name1="HEART BREAKERS";
    Tracks[52].url="https://www.youtube.com/watch?v=YR12Z8f1Dh8";

    Tracks[53].name="NENJUKKUL PEIDHIDUM";
    Tracks[53].artist_name="HARRIS JAYARAJ";
    Tracks[53].album_name="VAARANAM AAYIRAM";
    Tracks[53].genre_name="MELODY";
    Tracks[53].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[53].playlist_name2="INIYA IRAVU";
    Tracks[53].url="https://www.youtube.com/watch?v=FzLpP8VBC6E";

    Tracks[54].name="SIRIKKADHEY";
    Tracks[54].artist_name="ANIRUDH RAVICHANDER";
    Tracks[54].album_name="REMO";
    Tracks[54].genre_name="MELODY";
    Tracks[54].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[54].url="https://www.youtube.com/watch?v=iiVANEoXeLY";

    Tracks[55].name="ENGEYUM KADHAL";
    Tracks[55].artist_name="HARRIS JAYARAJ";
    Tracks[55].album_name="ENGEYUM KADHAL";
    Tracks[55].genre_name="MELODY";
    Tracks[55].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[55].url="https://www.youtube.com/watch?v=OH3_Jna80Uk";

    Tracks[56].name="UNAKAGA";
    Tracks[56].artist_name="A.R.RAHMAN";
    Tracks[56].album_name="BIGIL";
    Tracks[56].genre_name="LOVE";
    Tracks[56].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[56].playlist_name2="INIYA IRAVU";
    Tracks[56].url="https://www.youtube.com/watch?v=IdDaf8Rr33E";

    Tracks[57].name="NEW YORK";
    Tracks[57].artist_name="A.R.RAHMAN";
    Tracks[57].album_name="SILLUNU ORU KADHAL";
    Tracks[57].genre_name="MELODY";
    Tracks[57].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[57].url="https://www.youtube.com/watch?v=OjU54VhRFbU";

    Tracks[58].name="OSAKA OSAKA";
    Tracks[58].artist_name="ANIRUDH RAVICHANDER";
    Tracks[58].album_name="VANAKKAM CHENNAI";
    Tracks[58].genre_name="LOVE";
    Tracks[58].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[58].url="https://www.youtube.com/watch?v=Ml5smnK5Taw";

    Tracks[59].name="MARUVAARTHAI";
    Tracks[59].artist_name="SID SRIRAM";
    Tracks[59].album_name="ENAI NOKKI PAAYUM THOTA";
    Tracks[59].genre_name="LOVE";
    Tracks[59].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[59].playlist_name2="INIYA IRAVU";
    Tracks[59].url="https://www.youtube.com/watch?v=U3lyojCm6jA";

    Tracks[60].name="ANBE ANBE";
    Tracks[60].artist_name="G.V.PRAKASH KUMAR";
    Tracks[60].album_name="DARLING";
    Tracks[60].genre_name="LOVE";
    Tracks[60].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[60].url="https://www.youtube.com/watch?v=YR4fS1segho";

    Tracks[61].name="UN VIZHIGALIL";
    Tracks[61].artist_name="ANIRUDH RAVICHANDER";
    Tracks[61].album_name="MAAN KARATE";
    Tracks[61].genre_name="MELODY";
    Tracks[61].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[61].url="https://www.youtube.com/watch?v=8T7WQrcyE9s";

    Tracks[62].name="DOPE TRACK";
    Tracks[62].artist_name="YUVAN SHANKAR RAJA";
    Tracks[62].album_name="PYAAR PREMA KAADHAL";
    Tracks[62].genre_name="MOOD";
    Tracks[62].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[62].playlist_name2="INIYA IRAVU";
    Tracks[62].url="https://www.youtube.com/watch?v=SSrdUo0IrAc";

    Tracks[63].name="OTHAYADI PAATHAIYILE";
    Tracks[63].artist_name="ANIRUDH RAVICHANDER";
    Tracks[63].album_name="KANAA";
    Tracks[63].genre_name="LOVE";
    Tracks[63].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[63].url="https://www.youtube.com/watch?v=qP8e7lFdEho";

    Tracks[64].name="TAK BAK";
    Tracks[64].artist_name="ANIRUDH RAVICHANDER";
    Tracks[64].album_name="THANGAMAGAN";
    Tracks[64].genre_name="LOVE";
    Tracks[64].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[64].url="https://www.youtube.com/watch?v=Zl7B70EQeVo";

    Tracks[65].name="MAYA NADHI";
    Tracks[65].artist_name="SANTHOSH NARAYANAN";
    Tracks[65].album_name="KABALI";
    Tracks[65].genre_name="MELODY";
    Tracks[65].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[65].playlist_name2="INIYA IRAVU";
    Tracks[65].url="https://www.youtube.com/watch?v=9cHXA6l4e4Q";

    Tracks[66].name="KAADHAL ORU";
    Tracks[66].artist_name="HARRIS JAYARAJ";
    Tracks[66].album_name="OK OK";
    Tracks[66].genre_name="LOVE";
    Tracks[66].playlist_name1="ROMANTIC ACOUSTICS";
    Tracks[66].url="https://www.youtube.com/watch?v=xAfHFFi0O6E";

    Tracks[67].name="POOKKAL POOKKUM";
    Tracks[67].artist_name="G.V.PRAKASH KUMAR";
    Tracks[67].album_name="MADARASAPATTINAM";
    Tracks[67].genre_name="MELODY";
    Tracks[67].playlist_name1="INIYA IRAVU";
    Tracks[67].url="https://www.youtube.com/watch?v=nWxGhq_lBII";

    Tracks[68].name="KANNANA KANNEY";
    Tracks[68].artist_name="D.IMMAN";
    Tracks[68].album_name="VISWASAM";
    Tracks[68].genre_name="MELODY";
    Tracks[68].playlist_name1="INYA IRAVU";
    Tracks[68].url="https://www.youtube.com/watch?v=FysV6XnDlQk";

    Tracks[69].name="NEETHANE";
    Tracks[69].artist_name="A.R.RAHMAN";
    Tracks[69].album_name="MERSAL";
    Tracks[69].genre_name="MELODY";
    Tracks[69].playlist_name1="INIYA IRAVU";
    Tracks[69].url="https://www.youtube.com/watch?v=fWajtP80g54";

    Tracks[70].name="NAAN UN";
    Tracks[70].artist_name="A.R.RAHMAN";
    Tracks[70].album_name="24";
    Tracks[70].genre_name="MELODY";
    Tracks[70].playlist_name1="INIYA IRAVU";
    Tracks[70].url="https://www.youtube.com/watch?v=jRDCWQP7rjI";

    Tracks[71].name="YAANJI";
    Tracks[71].artist_name="ANIRUDH RAVICHANDER";
    Tracks[71].album_name="VIKRAM VEDHA";
    Tracks[71].genre_name="LOVE";
    Tracks[71].playlist_name1="INIYA IRAVU";
    Tracks[71].url="https://www.youtube.com/watch?v=Y3-PeuQ7nvY";

    Tracks[72].name="KAADHAL VAITHU";
    Tracks[72].artist_name="YUVAN SHANKAR RAJA";
    Tracks[72].album_name="DEEPAVALI";
    Tracks[72].genre_name="MOOD";
    Tracks[72].playlist_name1="INIYA IRAVU";
    Tracks[72].url="https://www.youtube.com/watch?v=F-nbd9_fxE0";

    Tracks[73].name="USURE";
    Tracks[73].artist_name="G.V.PRAKASH KUMAR";
    Tracks[73].album_name="SIVAPU MANJAL PACHAI";
    Tracks[73].genre_name="MELODY";
    Tracks[73].playlist_name1="INIYA IRAVU";
    Tracks[73].url="https://www.youtube.com/watch?v=27U4UPhHqjE";

    Tracks[73].name="NEEYUM NAANUM";
    Tracks[73].artist_name="ANIRUDH RAVICHANDER";
    Tracks[73].album_name="NAANUM ROWDY THAAN";
    Tracks[73].genre_name="LOVE";
    Tracks[73].playlist_name1="INIYA IRAVU";
    Tracks[73].url="https://www.youtube.com/watch?v=fYkQzTAx3Yo";

    Tracks[74].name="NEEYUM NAANUM ANBE";
    Tracks[74].artist_name="HIP HOP THAMIZHA";
    Tracks[74].album_name="IMAIKKA NODIGAL";
    Tracks[74].genre_name="LOVE";
    Tracks[74].playlist_name1="INIYA IRAVU";
    Tracks[74].url="https://www.youtube.com/watch?v=dImiR3Sr8Wo";

    Tracks[75].name="ANBAE PERANBAE";
    Tracks[75].artist_name="SID SRIRAM";
    Tracks[75].album_name="NGK";
    Tracks[75].genre_name="LOVE";
    Tracks[75].playlist_name1="INIYA IRAVU";
    Tracks[75].url="https://www.youtube.com/watch?v=N_iW0VC3IdI";

    Tracks[76].name="MAARIS ANANDHI";
    Tracks[76].artist_name="YUVAN SHANKAR RAJA";
    Tracks[76].album_name="MAARI 2";
    Tracks[76].genre_name="MELODY";
    Tracks[76].playlist_name1="INIYA IRAVU";
    Tracks[76].url="https://www.youtube.com/watch?v=AGiVsZGmkJU";

    Tracks[77].name="INNUM KONJA NERAM";
    Tracks[77].artist_name="A.R.RAHMAN";
    Tracks[77].album_name="MARYAN";
    Tracks[77].genre_name="MELODY";
    Tracks[77].playlist_name1="INIYA IRAVU";
    Tracks[77].url="https://www.youtube.com/watch?v=I8UrKhurkuk";

    Tracks[78].name="UN MELA ORU KANNU";
    Tracks[78].artist_name="D.IMMAN";
    Tracks[78].album_name="RAJINI MURUGAN";
    Tracks[78].genre_name="LOVE";
    Tracks[78].playlist_name1="INIYA IRAVU";
    Tracks[78].url="https://www.youtube.com/watch?v=nngwP1WWva4";

    Tracks[79].name="AYYAYO";
    Tracks[79].artist_name="G.V.PRAKASH KUMAR";
    Tracks[79].album_name="AADUKALAM";
    Tracks[79].genre_name="MELODY";
    Tracks[79].playlist_name1="INIYA IRAVU";
    Tracks[79].url="https://www.youtube.com/watch?v=uxb-TMoqb9k";

    Tracks[80].name="ENKEYOO PAARTHA";
    Tracks[80].artist_name="YUVAN SHANKAR RAJA";
    Tracks[80].album_name="YAARADI NEE MOHINI";
    Tracks[80].genre_name="MOOD";
    Tracks[80].playlist_name1="INIYA IRAVU";
    Tracks[80].url="https://www.youtube.com/watch?v=tK6Cq1B-J1Q";

    Tracks[81].name="CHILLENA";
    Tracks[81].artist_name="G.V.PRAKASH KUMAR";
    Tracks[81].album_name="RAJA RANI";
    Tracks[81].genre_name="LOVE";
    Tracks[81].playlist_name1="INIYA IRAVU";
    Tracks[81].url="https://www.youtube.com/watch?v=kQBuN9e_qbU";

    Tracks[82].name="IDHAZHIN ORAM";
    Tracks[82].artist_name="ANIRUDH RAVICHANDER";
    Tracks[82].album_name="THREE";
    Tracks[82].genre_name="MELODY";
    Tracks[82].playlist_name1="INIYA IRAVU";
    Tracks[82].url="https://www.youtube.com/watch?v=lZORMUufA_Y";

    Tracks[83].name="THULI THULI";
    Tracks[83].artist_name="YUVAN SHANKAR RAJA";
    Tracks[83].album_name="PAIYA";
    Tracks[83].genre_name="LOVE";
    Tracks[83].playlist_name1="INIYA IRAVU";
    Tracks[83].url="https://www.youtube.com/watch?v=v-hL3sks2qI";

    Tracks[84].name="GULEBA";
    Tracks[84].artist_name="ANIRUDH RAVICHANDER";
    Tracks[84].album_name="GULEBAGAVALI";
    Tracks[84].genre_name="PARTY";
    Tracks[84].playlist_name1="PARTY TONIGHT";
    Tracks[84].url="https://www.youtube.com/watch?v=QVgSyvzmbxw";

    Tracks[85].name="SINGLE PASANGA";
    Tracks[85].artist_name="HIP HOP THAMIZHA";
    Tracks[85].album_name="NATPE THUNAI";
    Tracks[85].genre_name="PARTY";
    Tracks[85].playlist_name1="PARTY TONIGHT";
    Tracks[85].url="https://www.youtube.com/watch?v=ybxt5dBVg5w";

    Tracks[86].name="BIGIL BIGIL BIGILUMA";
    Tracks[86].artist_name="A.R.RAHMAN";
    Tracks[86].album_name="BIGIL";
    Tracks[87].genre_name="PARTY";
    Tracks[87].playlist_name1="PARTY TONIGHT";
    Tracks[87].url="https://www.youtube.com/watch?v=wHhUta4UAq0";

    Tracks[88].name="MARANA MASS";
    Tracks[88].artist_name="ANIRUDH RAVICHANDER";
    Tracks[88].album_name="PETTA";
    Tracks[88].genre_name="PARTY";
    Tracks[88].playlist_name1="PARTY TONIGHT";
    Tracks[88].url="https://www.youtube.com/watch?v=88iypMO9H7g";

    Tracks[89].name="BAGULU ODAYUM DAGULU MAARI";
    Tracks[89].artist_name="ANIRUDH RAVICHANDER";
    Tracks[89].album_name="MAARI";
    Tracks[89].genre_name="PARTY";
    Tracks[89].playlist_name1="PARTY TONIGHT";
    Tracks[89].url="https://www.youtube.com/watch?v=PKQNh8dVp2U";

    Tracks[90].name="PAISA NOTE";
    Tracks[90].artist_name="HIP HOP THAMIZHA";
    Tracks[90].album_name="COMALI";
    Tracks[90].genre_name="PARTY";
    Tracks[90].playlist_name1="PARTY TONIGHT";
    Tracks[90].url="https://www.youtube.com/watch?v=lPg2iuMAdLc";

    Tracks[91].name="UDHUNGADA SANGU";
    Tracks[91].artist_name="ANIRUDH RAVICHANDER";
    Tracks[91].album_name="VIP";
    Tracks[91].genre_name="PARTY";
    Tracks[91].playlist_name1="PARTY TONIGHT";
    Tracks[91].url="https://www.youtube.com/watch?v=RCXzH27eOIA";

    Tracks[92].name="ROWDY BABY";
    Tracks[92].artist_name="DHANUSH";
    Tracks[92].album_name="MAARI 2";
    Tracks[92].genre_name="PARTY";
    Tracks[92].playlist_name1="PARTY TONIGHT";
    Tracks[92].url="https://www.youtube.com/watch?v=x6Q7c9RyMzk";

    Tracks[93].name="SODAKKU";
    Tracks[93].artist_name="ANIRUDH RAVICHANDER";
    Tracks[93].album_name="THAANA SERNDHA KOOTAM";
    Tracks[93].genre_name="FOLK";
    Tracks[93].playlist_name1="PARTY TONIGHT";
    Tracks[93].url="https://www.youtube.com/watch?v=pn6M7_L1JbQ";

    Tracks[94].name="THE MAARI SWAG";
    Tracks[94].artist_name="ANIRUDH RAVICHANDER";
    Tracks[94].album_name="MAARI";
    Tracks[94].genre_name="PARTY";
    Tracks[94].playlist_name1="PARTY TONIGHT";
    Tracks[94].url="https://www.youtube.com/watch?v=AeY7_k77zKg";

    Tracks[95].name="TAKKUNU TAKKUNU";
    Tracks[95].artist_name="HIP HOP THAMZIHA";
    Tracks[95].album_name="MR.LOCAL";
    Tracks[95].genre_name="LOVE";
    Tracks[95].playlist_name1="PARTY TONIGHT";
    Tracks[95].url="https://www.youtube.com/watch?v=meITXEnkPaA";

    Tracks[96].name="OTHA SOLLALA";
    Tracks[96].artist_name="G.V.PRAKASH KUMAR";
    Tracks[96].album_name="AADUKALAM";
    Tracks[96].genre_name="FOLK";
    Tracks[96].playlist_name1="PARTY TONIGHT";
    Tracks[96].url="https://www.youtube.com/watch?v=vXLAIaSkFIQ";

    Tracks[97].name="DON'U DON'U DON'U";
    Tracks[97].artist_name="ANIRUDH RAVICHANDER";
    Tracks[97].album_name="MAARI";
    Tracks[97].genre_name="LOVE";
    Tracks[97].playlist_name1="PARTY TONIGHT";
    Tracks[97].url="https://www.youtube.com/watch?v=A_z5g0_hJN8";

    Tracks[98].name="KARUTHAVANLAAM GALEEJAAM";
    Tracks[98].artist_name="ANIRUDH RAVICHANDER";
    Tracks[98].album_name="VELAIKARAN";
    Tracks[98].genre_name="FOLK";
    Tracks[98].playlist_name1="PARTY TONIGHT";
    Tracks[98].url="https://www.youtube.com/watch?v=es-5OLRrUf8";

    Tracks[99].name="MAARI THARA LOCAL";
    Tracks[99].artist_name="DHANUSH";
    Tracks[99].album_name="MAARI";
    Tracks[99].genre_name="FOLK";
    Tracks[99].playlist_name1="PARTY TONIGHT";
    Tracks[99].url="https://www.youtube.com/watch?v=OViH68fJUhM";

    Tracks[100].name="WHAT A KARVAAD";
    Tracks[100].artist_name="DHANUSH";
    Tracks[100].album_name="VIP";
    Tracks[100].genre_name="FOLK";
    Tracks[100].playlist_name1="PARTY TONIGHT";
    Tracks[100].url="https://www.youtube.com/watch?v=P2YRN8iGQ6g";

    Tracks[101].name="AALUMA DOLUMA";
    Tracks[101].artist_name="ANIRUDH RAVICHANDER";
    Tracks[101].album_name="VEDHALAM";
    Tracks[101].genre_name="FOLK";
    Tracks[101].playlist_name1="PARTY TONIGHT";
    Tracks[101].url="https://www.youtube.com/watch?v=2ogKpj5QuSY";

    Tracks[102].name="MERSALAAYITTEN";
    Tracks[102].artist_name="A.R.RAHMAN";
    Tracks[102].album_name="I";
    Tracks[102].genre_name="LOVE";
    Tracks[102].playlist_name1="PARTY TOBIGHT";
    Tracks[102].url="https://www.youtube.com/watch?v=uI_ug1H6u0k";

    Tracks[103].name="NAHNA NA NAH";
    Tracks[103].artist_name="YUVAN SHANKAR RAJA";
    Tracks[103].album_name="BIRIYANI";
    Tracks[103].genre_name="PARTY";
    Tracks[103].playlist_name1="PARTY TONIGHT";
    Tracks[103].url="https://www.youtube.com/watch?v=iyTMlo5uuzU";

    Tracks[104].name="HEARTUKULLA";
    Tracks[104].artist_name="VIVEK-MERVIN";
    Tracks[104].album_name="GULEBAGAVALI";
    Tracks[104].genre_name="PARTY";
    Tracks[104].playlist_name1="PARTY TONIGHT";
    Tracks[104].url="https://www.youtube.com/watch?v=OOP4FDO1XeU";

    Tracks[105].name="DANDANAKKA";
    Tracks[105].artist_name="D.IMMAN";
    Tracks[105].album_name="ROMEO JULIET";
    Tracks[105].genre_name="FOLK";
    Tracks[105].playlist_name1="PARTY TONIGHT";
    Tracks[105].url="https://www.youtube.com/watch?v=1zRe8UPF1tM";

    Tracks[106].name="TASAKKU TASAKKU";
    Tracks[106].artist_name="SAM.C.S";
    Tracks[106].album_name="VIKRAM VEDHA";
    Tracks[106].genre_name="PARTY";
    Tracks[106].playlist_name1="PARTY TONIGHT";
    Tracks[106].url="https://www.youtube.com/watch?v=Rw3ePD8qLcc";

    Tracks[107].name="CHENNAI CITY GANGSTA";
    Tracks[107].artist_name="ANIRUDH RAVICHANDER";
    Tracks[107].album_name="VANAKKAM CHENNAI";
    Tracks[107].genre_name="PARTY";
    Tracks[107].playlist_name1="PARTY TONIGHT";
    Tracks[107].url="https://www.youtube.com/watch?v=hAn75DAONqs";

    Tracks[108].name="VILAYAADU MANKATHA";
    Tracks[108].artist_name="YUVAN SHANKAR RAJA";
    Tracks[108].album_name="MANKATHA";
    Tracks[108].genre_name="PARTY";
    Tracks[108].playlist_name1="PARTY TONIGHT";
    Tracks[108].url="https://www.youtube.com/watch?v=fhdLTvl9a74";

    Tracks[109].name="DAAVUYA";
    Tracks[109].artist_name="SANTHOSH NARAYANAN";
    Tracks[109].album_name="REMO";
    Tracks[109].genre_name="PARTY";
    Tracks[109].playlist_name1="PARTY TONIGHT";
    Tracks[109].url="https://www.youtube.com/watch?v=GRKyx31fqjE";

    Tracks[110].name="LOCAL BOYS";
    Tracks[110].artist_name="DHANUSH";
    Tracks[110].album_name="ETHIR NEECHAL";
    Tracks[110].genre_name="PARTY";
    Tracks[110].playlist_name1="PARTY TONIGHT";
    Tracks[110].url="https://www.youtube.com/watch?v=0FsPYnmjkN4";

    Tracks[111].name="MACHI OPEN THE BOTTLE";
    Tracks[111].artist_name="YUVAN SHANKAR RAJA";
    Tracks[111].album_name="MANKATHA";
    Tracks[111].genre_name="PARTY";
    Tracks[111].playlist_name1="PARTY TONIGHT";
    Tracks[111].url="https://www.youtube.com/watch?v=68ixlbMQaY0";

    Tracks[112].name="SONAPAREEYA";
    Tracks[112].artist_name="A.R.RAHMAN";
    Tracks[112].album_name="MARYAN";
    Tracks[112].genre_name="PARTY";
    Tracks[112].playlist_name1="PARTY TONIGHT";
    Tracks[112].url="https://www.youtube.com/watch?v=NZE6pFlnSeU";

    initialize();

    for(i=0;i<=112;i++)
    {
        if(Tracks[i].artist_name=="ANIRUDH RAVICHANDER")
        {
            if(art[0]==NULL)
            {
                art[0]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[0];
                art[0]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="G.V.PRAKASH KUMAR")
        {
            if(art[1]==NULL)
            {
                art[1]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[1];
                art[1]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="BENNY DAYAL")
        {
            if(art[2]==NULL)
            {
                art[2]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[2];
                art[2]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="LEON JAMES")
        {
            if(art[3]==NULL)
            {
                art[3]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[3];
                art[3]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="SID SRIRAM")
        {
            if(art[4]==NULL)
            {
                art[4]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[4];
                art[4]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="HIP HOP THAMIZHA")
        {
            if(art[5]==NULL)
            {
                art[5]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[5];
                art[5]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="DHANUSH")
        {
            if(art[6]==NULL)
            {
                art[6]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[6];
                art[6]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="YUVAN SHANKAR RAJA")
        {
            if(art[7]==NULL)
            {
                art[7]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[7];
                art[7]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="SANTHOSH NARAYANAN")
        {
            if(art[8]==NULL)
            {
                art[8]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[8];
                art[8]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="DHRUV VIKRAM")
        {
            if(art[9]==NULL)
            {
                art[9]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[9];
                art[9]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="D.IMMAN")
        {
            if(art[10]==NULL)
            {
                art[10]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[10];
                art[10]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="HARRIS JAYARAJ")
        {
            if(art[11]==NULL)
            {
                art[11]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[11];
                art[11]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="VIVEK-MERVIN")
        {
            if(art[12]==NULL)
            {
                art[12]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[12];
                art[12]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="SAM.C.S")
        {
            if(art[13]==NULL)
            {
                art[13]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[13];
                art[13]=&Tracks[i];
            }
        }

        else if(Tracks[i].artist_name=="A.R.RAHMAN")
        {
            if(art[14]==NULL)
            {
                art[14]=&Tracks[i];
                Tracks[i].artist=NULL;
            }
            else
            {
                Tracks[i].artist=art[14];
                art[14]=&Tracks[i];
            }
        }

        if(Tracks[i].genre_name=="PARTY")
        {
            if(gen[0]==NULL)
            {
                gen[0]=&Tracks[i];
                Tracks[i].genre=NULL;
            }
            else
            {
                Tracks[i].genre=gen[0];
                gen[0]=&Tracks[i];
            }
        }

        else if(Tracks[i].genre_name=="MELODY")
        {
            if(gen[1]==NULL)
            {
                gen[1]=&Tracks[i];
                Tracks[i].genre=NULL;
            }
            else
            {
                Tracks[i].genre=gen[1];
                gen[1]=&Tracks[i];
            }
        }

        else if(Tracks[i].genre_name=="LOVE")
        {
            if(gen[2]==NULL)
            {
                gen[2]=&Tracks[i];
                Tracks[i].genre=NULL;
            }
            else
            {
                Tracks[i].genre=gen[2];
                gen[2]=&Tracks[i];
            }
        }

        else if(Tracks[i].genre_name=="MOOD")
        {
            if(gen[3]==NULL)
            {
                gen[3]=&Tracks[i];
                Tracks[i].genre=NULL;
            }
            else
            {
                Tracks[i].genre=gen[3];
                gen[3]=&Tracks[i];
            }
        }

        else if(Tracks[i].genre_name=="RAP")
        {
            if(gen[4]==NULL)
            {
                gen[4]=&Tracks[i];
                Tracks[i].genre=NULL;
            }
            else
            {
                Tracks[i].genre=gen[4];
                gen[4]=&Tracks[i];
            }
        }

        else if(Tracks[i].genre_name=="FOLK")
        {
            if(gen[5]==NULL)
            {
                gen[5]=&Tracks[i];
                Tracks[i].genre=NULL;
            }
            else
            {
                Tracks[i].genre=gen[5];
                gen[5]=&Tracks[i];
            }
        }

        if((Tracks[i].playlist_name1=="LATEST TAMIL")||(Tracks[i].playlist_name2=="LATEST TAMIL")||(Tracks[i].playlist_name3=="LATEST TAMIL"))
        {
            if(play[0]==NULL)
            {
                play[0]=&Tracks[i];
                Tracks[i].playlist1=NULL;
            }
            else
            {
                Tracks[i].playlist1=play[0];
                play[0]=&Tracks[i];
            }
        }

        if((Tracks[i].playlist_name1=="HEART BREAKERS")||(Tracks[i].playlist_name2=="HEART BREAKERS")||(Tracks[i].playlist_name3=="HEART BREAKERS"))
        {
            if(play[1]==NULL)
            {
                play[1]=&Tracks[i];
                Tracks[i].playlist2=NULL;
            }
            else
            {
                Tracks[i].playlist2=play[1];
                play[1]=&Tracks[i];
            }
        }

        if((Tracks[i].playlist_name1=="ROMANTIC ACOUSTICS")||(Tracks[i].playlist_name2=="ROMANTIC ACOUSTICS")||(Tracks[i].playlist_name3=="ROMANTIC ACOUSTICS"))
        {
            if(play[2]==NULL)
            {
                play[2]=&Tracks[i];
                Tracks[i].playlist3=NULL;
            }
            else
            {
                Tracks[i].playlist3=play[2];
                play[2]=&Tracks[i];
            }
        }

        if((Tracks[i].playlist_name1=="INIYA IRAVU")||(Tracks[i].playlist_name2=="INIYA IRAVU")||(Tracks[i].playlist_name3=="INIYA IRAVU"))
        {
            if(play[3]==NULL)
            {
                play[3]=&Tracks[i];
                Tracks[i].playlist4=NULL;
            }
            else
            {
                Tracks[i].playlist4=play[3];
                play[3]=&Tracks[i];
            }
        }

        if((Tracks[i].playlist_name1=="PARTY TONIGHT")||(Tracks[i].playlist_name2=="PARTY TONIGHT")||(Tracks[i].playlist_name3=="PARTY TOBIGHT"))
        {
            if(play[4]==NULL)
            {
                play[4]=&Tracks[i];
                Tracks[i].playlist5=NULL;
            }
            else
            {
                Tracks[i].playlist5=play[4];
                play[4]=&Tracks[i];
            }
        }

        if(Tracks[i].album_name=="MASTER")
        {
            if(alb[0]==NULL)
            {
                alb[0]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[0];
                alb[0]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="SOORARAI POTTRU")
        {
            if(alb[1]==NULL)
            {
                alb[1]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[1];
                alb[1]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="KANNUM KANNUM KOLLAIYADITHAL")
        {
            if(alb[2]==NULL)
            {
                alb[2]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[2];
                alb[2]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="OH MY KADAVULE")
        {
            if(alb[3]==NULL)
            {
                alb[3]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[3];
                alb[3]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="DHARALA PRABHU")
        {
            if(alb[4]==NULL)
            {
                alb[4]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[4];
                alb[4]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="NAAN SIRITHAAL")
        {
            if(alb[5]==NULL)
            {
                alb[5]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[5];
                alb[5]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="PATTAS")
        {
            if(alb[6]==NULL)
            {
                alb[6]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[6];
                alb[6]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="HERO")
        {
            if(alb[7]==NULL)
            {
                alb[7]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[7];
                alb[7]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="ADITHYA VARMA")
        {
            if(alb[8]==NULL)
            {
                alb[8]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[8];
                alb[8]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="PSYCHO")
        {
            if(alb[9]==NULL)
            {
                alb[9]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[9];
                alb[9]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="RAJA RANI")
        {
            if(alb[10]==NULL)
            {
                alb[10]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[10];
                alb[10]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="TEDDY")
        {
            if(alb[11]==NULL)
            {
                alb[11]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[11];
                alb[11]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="DEEPAVALI")
        {
            if(alb[12]==NULL)
            {
                alb[12]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[12];
                alb[12]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VAARANAM AAYIRAM")
        {
            if(alb[13]==NULL)
            {
                alb[13]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[13];
                alb[13]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="KADAL")
        {
            if(alb[14]==NULL)
            {
                alb[14]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[14];
                alb[14]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MEESAYA MURUKKU")
        {
            if(alb[15]==NULL)
            {
                alb[15]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[15];
                alb[15]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="GULEBAGAVALI")
        {
            if(alb[16]==NULL)
            {
                alb[16]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[16];
                alb[16]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VANAKKAM CHENNAI")
        {
            if(alb[17]==NULL)
            {
                alb[17]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[17];
                alb[17]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MEYAADHA MAAN")
        {
            if(alb[18]==NULL)
            {
                alb[18]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[18];
                alb[18]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="PAIYA")
        {
            if(alb[19]==NULL)
            {
                alb[19]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[19];
                alb[19]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="ENGEYUM KADHAL")
        {
            if(alb[20]==NULL)
            {
                alb[20]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[20];
                alb[20]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="KAATRIN MOZHI")
        {
            if(alb[21]==NULL)
            {
                alb[21]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[21];
                alb[21]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="IMAIKKA NODIGAL")
        {
            if(alb[22]==NULL)
            {
                alb[22]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[22];
                alb[22]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="THREE")
        {
            if(alb[23]==NULL)
            {
                alb[23]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[23];
                alb[23]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MIRUTHAN")
        {
            if(alb[24]==NULL)
            {
                alb[24]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[24];
                alb[24]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="GOA")
        {
            if(alb[25]==NULL)
            {
                alb[25]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[25];
                alb[25]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="ANEGAN")
        {
            if(alb[26]==NULL)
            {
                alb[26]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[26];
                alb[26]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="RAAVANAN")
        {
            if(alb[27]==NULL)
            {
                alb[27]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[27];
                alb[27]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="ROMEO JULIET")
        {
            if(alb[28]==NULL)
            {
                alb[28]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[28];
                alb[28]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MANMADHAN")
        {
            if(alb[29]==NULL)
            {
                alb[29]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[29];
                alb[29]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MR.LOCAL")
        {
            if(alb[30]==NULL)
            {
                alb[30]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[30];
                alb[30]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VINNAI THAANDI VARUVAYA")
        {
            if(alb[31]==NULL)
            {
                alb[31]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[31];
                alb[31]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="I")
        {
            if(alb[32]==NULL)
            {
                alb[32]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[32];
                alb[32]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="REMO")
        {
            if(alb[33]==NULL)
            {
                alb[33]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[33];
                alb[33]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="OK OK")
        {
            if(alb[34]==NULL)
            {
                alb[34]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[34];
                alb[34]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="YAARADI NEE MOHINI")
        {
            if(alb[35]==NULL)
            {
                alb[35]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[35];
                alb[35]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="BIGIL")
        {
            if(alb[36]==NULL)
            {
                alb[36]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[36];
                alb[36]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="SILLUNU ORU KADHAL")
        {
            if(alb[37]==NULL)
            {
                alb[37]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[37];
                alb[37]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="ENAI NOKKI PAAYUM THOTA")
        {
            if(alb[38]==NULL)
            {
                alb[38]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[38];
                alb[38]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="DARLING")
        {
            if(alb[39]==NULL)
            {
                alb[39]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[39];
                alb[39]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MAAN KARATE")
        {
            if(alb[40]==NULL)
            {
                alb[40]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[40];
                alb[40]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="PYAR PREMA KADHAL")
        {
            if(alb[41]==NULL)
            {
                alb[41]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[41];
                alb[41]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="KANA")
        {
            if(alb[42]==NULL)
            {
                alb[42]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[42];
                alb[42]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="THANGAMAGAN")
        {
            if(alb[43]==NULL)
            {
                alb[43]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[43];
                alb[43]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="KABALI")
        {
            if(alb[44]==NULL)
            {
                alb[44]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[44];
                alb[44]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="AADUKALAM")
        {
            if(alb[45]==NULL)
            {
                alb[45]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[45];
                alb[45]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="PETTA")
        {
            if(alb[46]==NULL)
            {
                alb[46]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[46];
                alb[46]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="COMALI")
        {
            if(alb[47]==NULL)
            {
                alb[47]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[47];
                alb[47]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="THAANA SERNDHA KOOTAM")
        {
            if(alb[48]==NULL)
            {
                alb[48]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[48];
                alb[48]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VEDHALAM")
        {
            if(alb[49]==NULL)
            {
                alb[49]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[49];
                alb[49]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="ETHIR NEECHAL")
        {
            if(alb[50]==NULL)
            {
                alb[50]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[50];
                alb[50]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MADARASAPATTINAM")
        {
            if(alb[51]==NULL)
            {
                alb[51]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[51];
                alb[51]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VISWASAM")
        {
            if(alb[52]==NULL)
            {
                alb[52]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[52];
                alb[52]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MERSAL")
        {
            if(alb[53]==NULL)
            {
                alb[53]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[53];
                alb[53]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="24")
        {
            if(alb[54]==NULL)
            {
                alb[54]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[54];
                alb[54]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VIKRAM VEDHA")
        {
            if(alb[55]==NULL)
            {
                alb[55]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[55];
                alb[55]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="SIVAPU MANJAL PACHAI")
        {
            if(alb[56]==NULL)
            {
                alb[56]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[56];
                alb[56]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="NAANUM ROWDY THAN")
        {
            if(alb[57]==NULL)
            {
                alb[57]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[57];
                alb[57]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="NGK")
        {
            if(alb[58]==NULL)
            {
                alb[58]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[58];
                alb[58]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MAARI 2")
        {
            if(alb[59]==NULL)
            {
                alb[59]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[59];
                alb[59]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MARYAN")
        {
            if(alb[60]==NULL)
            {
                alb[60]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[60];
                alb[60]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="RAJINIMURUGAN")
        {
            if(alb[61]==NULL)
            {
                alb[61]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[61];
                alb[61]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="NATPE THUNAI")
        {
            if(alb[62]==NULL)
            {
                alb[62]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[62];
                alb[62]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MAARI")
        {
            if(alb[63]==NULL)
            {
                alb[63]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[63];
                alb[63]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VIP")
        {
            if(alb[64]==NULL)
            {
                alb[64]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[64];
                alb[64]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="VELAIKARAN")
        {
            if(alb[65]==NULL)
            {
                alb[65]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[65];
                alb[65]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="MANKATHA")
        {
            if(alb[66]==NULL)
            {
                alb[66]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[66];
                alb[66]=&Tracks[i];
            }
        }

        else if(Tracks[i].album_name=="BIRIYANI")
        {
            if(alb[67]==NULL)
            {
                alb[67]=&Tracks[i];
                Tracks[i].album=NULL;
            }
            else
            {
                Tracks[i].album=alb[67];
                alb[67]=&Tracks[i];
            }
        }
    }

    int opt1,opt2,opt3,opt4;
    Song *temp,*nav,*tcus;
    char check,nopt;
    int count=1,move=0,cusc=1;

    cout<<"\t\t\t\t\t\t->->->->->Welcome to the Music Player<-<-<-<-<-"<<endl;
    cout<<"\t\tThis player consists of collection of over hundred songs from over 60 albums and 15 different artists and various genres"<<endl;
    cout<<"\t\tIn this player the user can create one custom playlist for themselves"<<endl;
    cout<<"\t\tThe user interface will be menu driven and the user can select the from the menu"<<endl;
    cout<<"\t\tWhen the user wants to open a track it will be opened on the browser"<<endl;
    cout<<"\t\tMultiple tracks can be opened in succession"<<endl;
    cout<<"\t\tMain menu:"<<endl;
    cout<<"\t\t1. Search and open songs from existing playlists"<<endl;
    cout<<"\t\t2. Create a custom playlist for yourself"<<endl;
    cout<<"\t\tEnter the option:";
    cin>>opt1;
    cout<<endl<<endl;

    switch(opt1)
    {
        case 1:
            cout<<"Select any option from the menu below"<<endl;
            cout<<"Playlist menu->"<<endl;
            cout<<"1. View songs based on artists"<<endl;
            cout<<"2. View songs based on genre"<<endl;
            cout<<"3. View songs based on playlists made by Music player"<<endl;
            cout<<"4. View songs based on album"<<endl;
            cout<<"Enter the option:";
            cin>>opt2;
            switch(opt2)
            {
                case 1:
                    cout<<"Select your favourite artist from the menu below"<<endl;
                    cout<<"Artist menu->"<<endl;
                    cout<<"1. Anirudh Ravichander"<<endl;
                    cout<<"2. G.V.Prakash kumar"<<endl;
                    cout<<"3. Benny Dayal"<<endl;
                    cout<<"4. Leon James"<<endl;
                    cout<<"5. Sid Sriram"<<endl;
                    cout<<"6. Hip Hop Thamizha"<<endl;
                    cout<<"7. Dhanush"<<endl;
                    cout<<"8. Yuvan Shankar Raja"<<endl;
                    cout<<"9. Santhosh Narayanan"<<endl;
                    cout<<"10.Dhruv Vikram"<<endl;
                    cout<<"11.D.Imman"<<endl;
                    cout<<"12.Harris Jayaraj"<<endl;
                    cout<<"13.Vivek-Mervin"<<endl;
                    cout<<"14.Sam.C.S"<<endl;
                    cout<<"15.A.R.Rahman"<<endl;
                    cout<<"Enter the artist from which you want to choose the track(option)";
                    cin>>opt3;
                    switch(opt3)
                    {
                        case 1:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[0];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r1:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r1;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[0];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art1:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art1;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[1];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r2:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r2;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[1];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art2:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art2;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 3:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[2];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r3:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r3;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[2];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art3:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art3;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 4:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[3];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r4:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r4;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[3];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art4:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art4;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 5:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[4];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r5:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r5;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[4];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art5:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art5;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 6:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[5];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r6:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r6;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[5];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art6:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art6;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 7:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[6];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r7:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r7;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[6];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art7:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art7;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 8:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[7];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r8:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r8;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[7];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art8:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art8;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 9:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[8];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r9:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r9;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[8];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art9:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art9;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 10:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[9];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r10:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r10;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[9];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art10:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art10;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 11:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[10];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r11:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r11;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[10];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art11:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art11;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 12:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[11];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r12:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r12;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[11];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art12:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art12;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 13:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[12];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r13:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r13;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[12];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art13:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art13;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 14:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[13];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r14:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r14;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[13];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art14:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art14;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 15:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below:"<<endl;
                            temp=art[14];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Genre:"<<temp->genre_name<<endl;
                                cout<<endl;
                                temp=temp->artist;
                                count++;
                                if(count%5==0||temp->artist==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        r15:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter the correct option"<<endl;
                                            goto r15;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=art[14];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->artist;
                                                mov++;
                                            }
                                            art15:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->artist;
                                                goto art15;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                    }
                    break;
                case 2:
                    cout<<"Select your favourite genre from the menu below"<<endl;
                    cout<<"1. Party"<<endl;
                    cout<<"2. Melody"<<endl;
                    cout<<"3. Love"<<endl;
                    cout<<"4. Mood"<<endl;
                    cout<<"5. Rap"<<endl;
                    cout<<"6. Folk"<<endl;
                    cout<<"Enter the genre from which you want to choose the track(option):";
                    cin>>opt3;
                    switch(opt3)
                    {
                        case 1:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=gen[0];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Artist"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->genre;
                                count++;
                                if(count%5==0||temp->genre==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        g1:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto g1;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=gen[0];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->genre;
                                                mov++;
                                            }
                                            gn1:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->genre;
                                                goto gn1;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=gen[1];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Artist"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->genre;
                                count++;
                                if(count%5==0||temp->genre==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        g2:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto g2;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=gen[1];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->genre;
                                                mov++;
                                            }
                                            gn2:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->genre;
                                                goto gn2;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 3:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=gen[2];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Artist"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->genre;
                                count++;
                                if(count%5==0||temp->genre==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        g3:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto g3;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=gen[2];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->genre;
                                                mov++;
                                            }
                                            gn3:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->genre;
                                                goto gn3;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 4:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=gen[3];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Artist"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->genre;
                                count++;
                                if(count%5==0||temp->genre==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        g4:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto g4;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=gen[3];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->genre;
                                                mov++;
                                            }
                                            gn4:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->genre;
                                                goto gn4;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 5:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=gen[4];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Artist"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->genre;
                                count++;
                                if(count%5==0||temp->genre==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        g5:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto g5;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=gen[4];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->genre;
                                                mov++;
                                            }
                                            gn5:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->genre;
                                                goto gn5;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 6:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=gen[5];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Album:"<<temp->album_name<<endl;
                                cout<<"Artist"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->genre;
                                count++;
                                if(count%5==0||temp->genre==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        g6:
                                        cout<<"Enter the S.No of the song to open in browser:";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto g6;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=gen[5];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->genre;
                                                mov++;
                                            }
                                            gn6:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->genre;
                                                goto gn6;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                    }
                    break;
                case 3:
                    cout<<"Select the playlist you want to view"<<endl;
                    cout<<"1. Latest Tamil"<<endl;
                    cout<<"2. Heart Breakers"<<endl;
                    cout<<"3. Romantic Acoustics"<<endl;
                    cout<<"4. Iniya Iravu"<<endl;
                    cout<<"5. Party Tonight"<<endl;
                    cout<<"Enter the playlist you want to view(option):"<<endl;
                    cin>>opt3;
                    switch(opt3)
                    {
                        case 1:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[0];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist1;
                                count++;
                                if(count%5==0||temp->playlist1==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        p1:
                                        cout<<"Enter the S.No of the song to open in browser";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto p1;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[0];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->playlist1;
                                                mov++;
                                            }
                                            pl1:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->playlist1;
                                                goto pl1;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[1];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist2;
                                count++;
                                if(count%5==0||temp->playlist2==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        p2:
                                        cout<<"Enter the S.No of the song to open in browser";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto p2;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[1];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->playlist2;
                                                mov++;
                                            }
                                            pl2:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->playlist2;
                                                goto pl2;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 3:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[2];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist3;
                                count++;
                                if(count%5==0||temp->playlist3==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        p3:
                                        cout<<endl;
                                        cout<<"Enter the S.No of the song to open in browser";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto p3;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[2];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->playlist3;
                                                mov++;
                                            }
                                            pl3:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->playlist3;
                                                goto pl3;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 4:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[3];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist4;
                                count++;
                                if(count%5==0||temp->playlist4==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        p4:
                                        cout<<"Enter the S.No of the song to open in browser";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto p4;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[3];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->playlist4;
                                                mov++;
                                            }
                                            pl4:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->playlist4;
                                                goto pl4;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 5:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[4];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist5;
                                count++;
                                if(count%5==0||temp->playlist5==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        p5:
                                        cout<<"Enter the S.No of the song to open in browser";
                                        cin>>opt4;
                                        if(opt4>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto p5;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[4];
                                            while(mov<opt4-1)
                                            {
                                                nav=nav->playlist5;
                                                mov++;
                                            }
                                            pl5:
                                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                                            cout<<"Do you want to open another song?(Y/N):";
                                            cin>>nopt;
                                            if(nopt=='Y'||nopt=='y')
                                            {
                                                nav=nav->playlist5;
                                                goto pl5;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                    }
                    break;
                case 4:
                    int j=1;
                    char ch;
                    cout<<"Albums are listed below"<<endl;
                    for(j=1;j<=68;j++)
                    {
                        cout<<j<<"."<<list[j-1]<<endl;
                        if(j%5==0||j==68)
                        {
                            cout<<"Did you find the album you are looking for?(Y/N):";
                            cin>>ch;
                            if(ch=='Y'||ch=='y')
                            {
                                cout<<endl<<"Enter the album number to view the tracks:";
                                cin>>opt3;
                                break;
                            }
                        }
                    }
                    switch(opt3)
                    {
                        case 1:
                            count=1;
                            cout<<list[0]<<":"<<endl;
                            temp=alb[0];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a1:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a1;
                            }
                            nav=alb[0];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al1:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al1;
                            }
                            break;
                        case 2:
                            count=1;
                            cout<<list[1]<<":"<<endl;
                            temp=alb[1];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a2:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a2;
                            }
                            nav=alb[1];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al2:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al2;
                            }
                            break;
                        case 3:
                            count=1;
                            cout<<list[2]<<":"<<endl;
                            temp=alb[2];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a3:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a3;
                            }
                            nav=alb[2];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al3:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al3;
                            }
                            break;
                        case 4:
                            count=1;
                            cout<<list[3]<<":"<<endl;
                            temp=alb[3];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a4:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a4;
                            }
                            nav=alb[3];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al4:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al4;
                            }
                            break;
                        case 5:
                            count=1;
                            cout<<list[4]<<":"<<endl;
                            temp=alb[4];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a5:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a5;
                            }
                            nav=alb[4];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al5:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al5;
                            }
                            break;
                        case 6:
                            count=1;
                            cout<<list[5]<<":"<<endl;
                            temp=alb[5];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a6:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a6;
                            }
                            nav=alb[5];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al6:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al6;
                            }
                            break;
                        case 7:
                            count=1;
                            cout<<list[6]<<":"<<endl;
                            temp=alb[6];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a7:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a7;
                            }
                            nav=alb[6];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al7:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al7;
                            }
                            break;
                        case 8:
                            count=1;
                            cout<<list[7]<<":"<<endl;
                            temp=alb[7];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a8:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a8;
                            }
                            nav=alb[7];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al8:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al8;
                            }
                            break;
                        case 9:
                            count=1;
                            cout<<list[8]<<":"<<endl;
                            temp=alb[8];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a9:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a9;
                            }
                            nav=alb[8];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al9:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al9;
                            }
                            break;
                        case 10:
                            count=1;
                            cout<<list[9]<<":"<<endl;
                            temp=alb[9];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a10:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a10;
                            }
                            nav=alb[9];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al10:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al10;
                            }
                            break;
                        case 11:
                            count=1;
                            cout<<list[10]<<":"<<endl;
                            temp=alb[10];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a11:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a11;
                            }
                            nav=alb[10];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al11:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al11;
                            }
                            break;
                        case 12:
                            count=1;
                            cout<<list[11]<<":"<<endl;
                            temp=alb[11];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a12:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a12;
                            }
                            nav=alb[11];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al12:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al12;
                            }
                            break;
                        case 13:
                            count=1;
                            cout<<list[12]<<":"<<endl;
                            temp=alb[12];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a13:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a13;
                            }
                            nav=alb[12];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al13:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al13;
                            }
                            break;
                        case 14:
                            count=1;
                            cout<<list[13]<<":"<<endl;
                            temp=alb[13];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a14:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a14;
                            }
                            nav=alb[13];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al14:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al14;
                            }
                            break;
                        case 15:
                            count=1;
                            cout<<list[14]<<":"<<endl;
                            temp=alb[14];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a15:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a15;
                            }
                            nav=alb[14];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al15:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al15;
                            }
                            break;
                        case 16:
                            count=1;
                            cout<<list[15]<<":"<<endl;
                            temp=alb[15];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a16:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a16;
                            }
                            nav=alb[15];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al16:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al16;
                            }
                            break;
                        case 17:
                            count=1;
                            cout<<list[16]<<":"<<endl;
                            temp=alb[16];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a17:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a17;
                            }
                            nav=alb[16];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al17:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al17;
                            }
                            break;
                        case 18:
                            count=1;
                            cout<<list[17]<<":"<<endl;
                            temp=alb[17];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a18:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a18;
                            }
                            nav=alb[17];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al18:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al18;
                            }
                            break;
                        case 19:
                            count=1;
                            cout<<list[18]<<":"<<endl;
                            temp=alb[18];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a19:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a19;
                            }
                            nav=alb[18];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al19:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al19;
                            }
                            break;
                        case 20:
                            count=1;
                            cout<<list[19]<<":"<<endl;
                            temp=alb[19];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a20:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a20;
                            }
                            nav=alb[19];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al20:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al20;
                            }
                            break;
                        case 21:
                            count=1;
                            cout<<list[20]<<":"<<endl;
                            temp=alb[20];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a21:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a21;
                            }
                            nav=alb[20];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al21:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al21;
                            }
                            break;
                        case 22:
                            count=1;
                            cout<<list[21]<<":"<<endl;
                            temp=alb[21];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a22:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a22;
                            }
                            nav=alb[21];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al22:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al22;
                            }
                            break;
                        case 23:
                            count=1;
                            cout<<list[22]<<":"<<endl;
                            temp=alb[22];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a23:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a23;
                            }
                            nav=alb[22];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al23:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al23;
                            }
                            break;
                        case 24:
                            count=1;
                            cout<<list[23]<<":"<<endl;
                            temp=alb[23];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a24:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a24;
                            }
                            nav=alb[23];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al24:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al24;
                            }
                            break;
                        case 25:
                            count=1;
                            cout<<list[24]<<":"<<endl;
                            temp=alb[24];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a25:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a25;
                            }
                            nav=alb[24];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al25:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al25;
                            }
                            break;
                        case 26:
                            count=1;
                            cout<<list[25]<<":"<<endl;
                            temp=alb[25];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a26:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a26;
                            }
                            nav=alb[25];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al26:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al26;
                            }
                            break;
                        case 27:
                            count=1;
                            cout<<list[26]<<":"<<endl;
                            temp=alb[26];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a27:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a27;
                            }
                            nav=alb[26];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al27:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al27;
                            }
                            break;
                        case 28:
                            count=1;
                            cout<<list[27]<<":"<<endl;
                            temp=alb[27];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a28:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a28;
                            }
                            nav=alb[27];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al28:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al28;
                            }
                            break;
                        case 29:
                            count=1;
                            cout<<list[28]<<":"<<endl;
                            temp=alb[28];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a29:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a29;
                            }
                            nav=alb[28];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al29:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al29;
                            }
                            break;
                        case 30:
                            count=1;
                            cout<<list[29]<<":"<<endl;
                            temp=alb[29];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a30:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a30;
                            }
                            nav=alb[29];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al30:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al30;
                            }
                            break;
                        case 31:
                            count=1;
                            cout<<list[30]<<":"<<endl;
                            temp=alb[30];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a31:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a31;
                            }
                            nav=alb[30];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al31:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al31;
                            }
                            break;
                        case 32:
                            count=1;
                            cout<<list[31]<<":"<<endl;
                            temp=alb[31];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a32:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a32;
                            }
                            nav=alb[31];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al32:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al32;
                            }
                            break;
                        case 33:
                            count=1;
                            cout<<list[32]<<":"<<endl;
                            temp=alb[32];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a33:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a33;
                            }
                            nav=alb[32];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al33:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al33;
                            }
                            break;
                        case 34:
                            count=1;
                            cout<<list[33]<<":"<<endl;
                            temp=alb[33];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a34:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a34;
                            }
                            nav=alb[33];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al34:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al34;
                            }
                            break;
                        case 35:
                            count=1;
                            cout<<list[34]<<":"<<endl;
                            temp=alb[34];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a35:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a35;
                            }
                            nav=alb[34];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al35:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al35;
                            }
                            break;
                        case 36:
                            count=1;
                            cout<<list[35]<<":"<<endl;
                            temp=alb[35];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a36:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a36;
                            }
                            nav=alb[35];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al36:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al36;
                            }
                            break;
                        case 37:
                            count=1;
                            cout<<list[36]<<":"<<endl;
                            temp=alb[36];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a37:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a37;
                            }
                            nav=alb[36];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al37:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al37;
                            }
                            break;
                        case 38:
                            count=1;
                            cout<<list[37]<<":"<<endl;
                            temp=alb[37];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a38:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a38;
                            }
                            nav=alb[37];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al38:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al38;
                            }
                            break;
                        case 39:
                            count=1;
                            cout<<list[38]<<":"<<endl;
                            temp=alb[38];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a39:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a39;
                            }
                            nav=alb[38];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al39:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al39;
                            }
                            break;
                        case 40:
                            count=1;
                            cout<<list[39]<<":"<<endl;
                            temp=alb[39];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a40:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a40;
                            }
                            nav=alb[39];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al40:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al40;
                            }
                            break;
                        case 41:
                            count=1;
                            cout<<list[40]<<":"<<endl;
                            temp=alb[40];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a41:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a41;
                            }
                            nav=alb[40];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al41:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al41;
                            }
                            break;
                        case 42:
                            count=1;
                            cout<<list[41]<<":"<<endl;
                            temp=alb[41];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a42:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a42;
                            }
                            nav=alb[41];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al42:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al42;
                            }
                            break;
                        case 43:
                            count=1;
                            cout<<list[42]<<":"<<endl;
                            temp=alb[42];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a43:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a43;
                            }
                            nav=alb[42];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al43:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al43;
                            }
                            break;
                        case 44:
                            count=1;
                            cout<<list[43]<<":"<<endl;
                            temp=alb[43];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a44:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a44;
                            }
                            nav=alb[43];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al44:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al44;
                            }
                            break;
                        case 45:
                            count=1;
                            cout<<list[44]<<":"<<endl;
                            temp=alb[44];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a45:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a45;
                            }
                            nav=alb[44];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al45:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al45;
                            }
                            break;
                        case 46:
                            count=1;
                            cout<<list[45]<<":"<<endl;
                            temp=alb[45];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a46:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a46;
                            }
                            nav=alb[45];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al46:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al46;
                            }
                            break;
                        case 47:
                            count=1;
                            cout<<list[46]<<":"<<endl;
                            temp=alb[46];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a47:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a47;
                            }
                            nav=alb[46];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al47:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al47;
                            }
                            break;
                        case 48:
                            count=1;
                            cout<<list[47]<<":"<<endl;
                            temp=alb[47];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a48:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a48;
                            }
                            nav=alb[47];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al48:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al48;
                            }
                            break;
                        case 49:
                            count=1;
                            cout<<list[48]<<":"<<endl;
                            temp=alb[48];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a49:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a49;
                            }
                            nav=alb[48];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al49:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al49;
                            }
                            break;
                        case 50:
                            count=1;
                            cout<<list[49]<<":"<<endl;
                            temp=alb[49];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a50:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a50;
                            }
                            nav=alb[49];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al50:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al50;
                            }
                            break;
                        case 51:
                            count=1;
                            cout<<list[50]<<":"<<endl;
                            temp=alb[50];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a51:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a51;
                            }
                            nav=alb[50];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al51:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al51;
                            }
                            break;
                        case 52:
                            count=1;
                            cout<<list[51]<<":"<<endl;
                            temp=alb[51];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a52:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a52;
                            }
                            nav=alb[51];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al52:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al52;
                            }
                            break;
                        case 53:
                            count=1;
                            cout<<list[52]<<":"<<endl;
                            temp=alb[52];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a53:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a53;
                            }
                            nav=alb[52];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al53:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al53;
                            }
                            break;
                        case 54:
                            count=1;
                            cout<<list[53]<<":"<<endl;
                            temp=alb[53];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a54:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a54;
                            }
                            nav=alb[53];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al54:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al54;
                            }
                            break;
                        case 55:
                            count=1;
                            cout<<list[54]<<":"<<endl;
                            temp=alb[54];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a55:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a55;
                            }
                            nav=alb[54];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al55:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al55;
                            }
                            break;
                        case 56:
                            count=1;
                            cout<<list[55]<<":"<<endl;
                            temp=alb[55];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a56:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a56;
                            }
                            nav=alb[55];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al56:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al56;
                            }
                            break;
                        case 57:
                            count=1;
                            cout<<list[56]<<":"<<endl;
                            temp=alb[56];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a57:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a57;
                            }
                            nav=alb[56];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al57:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al57;
                            }
                            break;
                        case 58:
                            count=1;
                            cout<<list[57]<<":"<<endl;
                            temp=alb[57];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a58:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a58;
                            }
                            nav=alb[57];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }

                            al58:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al58;
                            }
                            break;
                        case 59:
                            count=1;
                            cout<<list[58]<<":"<<endl;
                            temp=alb[58];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a59:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a59;
                            }
                            nav=alb[58];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al59:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al59;
                            }
                            break;
                        case 60:
                            count=1;
                            cout<<list[59]<<":"<<endl;
                            temp=alb[59];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a60:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a60;
                            }
                            nav=alb[59];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al60:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al60;
                            }
                            break;
                        case 61:
                            count=1;
                            cout<<list[60]<<":"<<endl;
                            temp=alb[60];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a61:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a62;
                            }
                            nav=alb[60];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al61:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al61;
                            }
                            break;
                        case 62:
                            count=1;
                            cout<<list[61]<<":"<<endl;
                            temp=alb[61];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a62:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a62;
                            }
                            nav=alb[61];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al62:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al62;
                            }
                            break;
                        case 63:
                            count=1;
                            cout<<list[62]<<":"<<endl;
                            temp=alb[62];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a63:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a63;
                            }
                            nav=alb[62];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al63:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al63;
                            }
                            break;
                        case 64:
                            count=1;
                            cout<<list[63]<<":"<<endl;
                            temp=alb[63];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a64:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a64;
                            }
                            nav=alb[63];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al64:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al64;
                            }
                            break;
                        case 65:
                            count=1;
                            cout<<list[64]<<":"<<endl;
                            temp=alb[64];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a65:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a65;
                            }
                            nav=alb[64];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al65:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al65;
                            }
                            break;
                        case 66:
                            count=1;
                            cout<<list[65]<<":"<<endl;
                            temp=alb[65];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a66:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a66;
                            }
                            nav=alb[65];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al66:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al66;
                            }
                            break;
                        case 67:
                            count=1;
                            cout<<list[66]<<":"<<endl;
                            temp=alb[66];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a67:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a67;
                            }
                            nav=alb[66];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al67:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al67;
                            }
                            break;
                        case 68:
                            count=1;
                            cout<<list[67]<<":"<<endl;
                            temp=alb[67];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Name:"<<temp->name<<endl;
                                cout<<endl;
                                temp=temp->album;
                                count++;
                            }
                            a68:
                            cout<<"Enter the S.No of the song you want to listen:";
                            cin>>opt4;
                            if(opt4>count)
                            {
                                cout<<endl<<"Invalid option!!! Enter valid option"<<endl;
                                goto a68;
                            }
                            nav=alb[67];
                            move=0;
                            while(move<opt4-1)
                            {
                                nav=nav->album;
                                move++;
                            }
                            al68:
                            ShellExecuteA(NULL,verb,nav->url,NULL,NULL,SW_SHOWNORMAL);
                            cout<<"Do you want to open another song?(Y/N):";
                            cin>>nopt;
                            if(nopt=='Y'||nopt=='y')
                            {
                                nav=nav->album;
                                goto al68;
                            }
                            break;
                    }
                    break;
            }
            break;
        case 2:
            int playlist_choice;
            char check_cont;
            Song *pre;
            cont:
                cout<<"\nThe songs will be listed in premade playlists select a song from it inorder to add it in your playlist";
                cout<<"\nPRE-MADE PLAYLISTS:";
                cout<<"1. Latest Tamil"<<endl;
                cout<<"2. Heart Breakers"<<endl;
                cout<<"3. Romantic Acoustics"<<endl;
                cout<<"4. Iniya Iravu"<<endl;
                cout<<"5. Party Tonight"<<endl;
                cout<<"Enter the playlist you want to view(option):"<<endl;
                cin>>playlist_choice;
                switch(playlist_choice)
                {
                    char check;
                    int count,song_choice;
                    case 1:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[0];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist1;
                                count++;
                                if(count%5==0||temp->playlist1==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        cp1:
                                        cout<<"Enter the S.No of the song to add it to your playlist";
                                        cin>>song_choice;
                                        if(song_choice>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto cp1;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[0];
                                            while(mov<song_choice-1)
                                            {
                                                nav=nav->playlist1;
                                                mov++;
                                            }
                                            if(cus==NULL)
                                            {
                                                cus=nav;
                                                nav->custom=NULL;
                                            }
                                            else
                                            {
                                                pre->custom=nav;
                                            }
                                            pre=nav;
                                            cout<<"Do you want to add another song? (y/n)"<<endl;
                                            cin>>check_cont;
                                            if(check_cont=='y'||check_cont=='Y')
                                                goto cont;
                                            else
                                                break;
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[1];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist2;
                                count++;
                                if(count%5==0||temp->playlist2==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        cp2:
                                        cout<<"Enter the S.No of the song to add it to your playlist";
                                        cin>>song_choice;
                                        if(song_choice>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto cp2;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[1];
                                            while(mov<song_choice-1)
                                            {
                                                nav=nav->playlist2;
                                                mov++;
                                            }
                                            if(cus==NULL)
                                            {
                                                cus=nav;
                                                nav->custom=NULL;
                                            }
                                            else
                                            {
                                                pre->custom=nav;
                                            }
                                            pre=nav;
                                            cout<<"Do you want to add another song? (y/n)"<<endl;
                                            cin>>check_cont;
                                            if(check_cont=='y'||check_cont=='Y')
                                                goto cont;
                                            else
                                                break;
                                        }
                                    }
                                }
                            }
                            break;
                        case 3:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[2];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist3;
                                count++;
                                if(count%5==0||temp->playlist3==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        cp3:
                                        cout<<endl;
                                        cout<<"Enter the S.No of the song to add in to your playlist";
                                        cin>>song_choice;
                                        if(song_choice>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto cp3;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[2];
                                            while(mov<song_choice-1)
                                            {
                                                nav=nav->playlist3;
                                                mov++;
                                            }
                                            if(cus==NULL)
                                            {
                                                cus=nav;
                                                nav->custom=NULL;
                                            }
                                            else
                                            {
                                                pre->custom=nav;
                                            }
                                            pre=nav;
                                            cout<<"Do you want to add another song? (y/n)"<<endl;
                                            cin>>check_cont;
                                            if(check_cont=='y'||check_cont=='Y')
                                                goto cont;
                                            else
                                                break;
                                        }
                                    }
                                }
                            }
                            break;
                        case 4:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[3];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist4;
                                count++;
                                if(count%5==0||temp->playlist4==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        cp4:
                                        cout<<"Enter the S.No of the song to add it to your playlist";
                                        cin>>song_choice;
                                        if(song_choice>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto cp4;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[3];
                                            while(mov<song_choice-1)
                                            {
                                                nav=nav->playlist4;
                                                mov++;
                                            }
                                            if(cus==NULL)
                                            {
                                                cus=nav;
                                                nav->custom=NULL;
                                            }
                                            else
                                            {
                                                pre->custom=nav;
                                            }
                                            pre=nav;
                                            cout<<"Do you want to add another song? (y/n)"<<endl;
                                            cin>>check_cont;
                                            if(check_cont=='y'||check_cont=='Y')
                                                goto cont;
                                            else
                                                break;
                                        }
                                    }
                                }
                            }
                            break;
                        case 5:
                            count=1;
                            cout<<endl<<endl;
                            cout<<"Songs are listed below"<<endl;
                            temp=play[4];
                            while(temp!=NULL)
                            {
                                cout<<"S.No:"<<count<<endl;
                                cout<<"Song:"<<temp->name<<endl;
                                cout<<"Artist:"<<temp->artist_name<<endl;
                                cout<<endl;
                                temp=temp->playlist5;
                                count++;
                                if(count%5==0||temp->playlist5==NULL)
                                {
                                    cout<<"Did you find the track you want?(Y/N):";
                                    cin>>check;
                                    cout<<endl;
                                    if(check=='Y'||check=='y')
                                    {
                                        cp5:
                                        cout<<"Enter the S.No of the song to add it to your playlist";
                                        cin>>song_choice;
                                        if(song_choice>count)
                                        {
                                            cout<<"Invalid option!!! Enter correct option"<<endl;
                                            goto cp5;
                                        }
                                        else
                                        {
                                            int mov=0;
                                            nav=play[4];
                                            while(mov<song_choice-1)
                                            {
                                                nav=nav->playlist5;
                                                mov++;
                                            }
                                            if(cus==NULL)
                                            {
                                                cus=nav;
                                                nav->custom=NULL;
                                            }
                                            else
                                            {
                                                pre->custom=nav;
                                            }
                                            pre=nav;
                                            cout<<"Do you want to add another song? (y/n)"<<endl;
                                            cin>>check_cont;
                                            if(check_cont=='y'||check_cont=='Y')
                                                goto cont;
                                            else
                                                break;
                                        }
                                    }
                                }
                            }
                            break;
                }
            tcus=cus;
            cusc=1;
            cout<<"Your custom playlist"<<endl;
            while(tcus!=NULL)
            {
                cout<<cusc<<"."<<tcus->name<<endl;
                cusc++;
            }
            cout<<"Enter the song number which you want to open:";
            cin>>opt4;
            tcus=cus;
            cusc=1;
            while(cusc<opt4)
            {
                tcus=tcus->custom;
                cusc++;
            }
            ShellExecuteA(NULL,verb,tcus->url,NULL,NULL,SW_SHOWNORMAL);
            break;
    }
    return 0;
}
