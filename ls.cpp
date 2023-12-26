#include <fstream>
#include <iostream>
using namespace std;
#include "class/Traffic_system.h" int main() {
Traffic_system civil_aviatio n;
//ÈôÎÄ¼þ²»´æÔÚ£¬ÔòÐÂ½¨ÎÄ¼þ
ofstream newfile( "flight information.txt", ios::app );
if (!n ewfile)
{
cerr << "ÎÄ¼þ\"flight information.txt\"	ÎÞ·¨´ò¿ª£¡ \n";
exit(2);
}
newfile.close();
int tab;
while(1)
{
cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>	»¶Ó­½øÈëº½¿ÕÊÛÆ±¹ÜÀíÏµÍ³
vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv"
***********"
'\******
Ö÷ ²Ë µ¥

***********"
<<
¡¢'******* *************************************************************** **********¡¢'
<< "ÄãÐèÒª×öÊ²Ã´£¿(Ñ¡Ôñ 0~4) " << endl;
cin >> tab;
while(!(tab == 1 || tab == 2 || tab == 3 || tab == 4 || tab == 5 || tab ==0))
{
cout << "ÇëÊäÈëÕýÈ·Ñ¡Ôñ(0~4):";
cin >> tab;
}
switch(tab)
{
case 1:
{
civil_aviatio n.Ma nage();
break;
}	//º½Ïß¹ÜÀí
case 2:
{
civil_aviatio n.Sca n();
break;
}	//¶©Æ±°ìÀí
case 3:
{
civil_aviatio n.Search();
break;
}	//ÍËÆ±°ìÀí
case 4:
{
civil_aviatio n.BookRefu nd();
break;
}
case 5: system("cls"); break;
case 0:return 0;	// ÍË³öÏµÍ³
}
ÎÄ¼þ	class/Traffic_system.h
#in elude <vector>
using n amespace std;
#include "flight.h"
//ÓÃÓÚ¶ÔÎÄ¼þµÄ²Ù×÷
class Traffic_system
{
public:
Traffic_system()
{
m_sum = 0;
}
void Man age();//	¹ÜÀíº½°àÐÅÏ¢
void Scan ();// ä¯ÀÀ
int Search(i nt in voke = 0);//	²éÑ¯¹¦ÄÜ
void BookRefu nd();¡¨	¶©Æ±ºÍÍËÆ±
private:
void Read_file();¡¨	¶ÁÈ¡ÎÄ¼þ
void Save_file();// ±£´æÎÄ¼þ private:
int m_sum;¡¨ ¼ÇÂ¼º½°àÊý
vector <Flight> v_array;// º½°àÀàÊý×é };
ÎÄ¼þ	class/Traffic_system.cpp
#in clude <fstream>
#in elude <iostream> using n amespace std;
#in elude "Traffic_system.h"
//¶ÁÈ¡ÎÄ¼þ
void Traffic_system::Read_file()
{
ifstream file( "flight in formatio n. txt");
if (!file)
{
cerr << "ÎÄ¼þ\"flight information.txt\"	ÎÞ·¨´ò¿ª£¡ \n";
exit(1);
}
m_sum = 0;
while (!file.eof())
{
Flight fly;
v_array.push_back(fly);¡¨
file >> v_array[m_sum++];
}
m_sum--;¡¨
file.close();
}
//±£´æÎÄ¼þ
void Traffic_system::Save_file()
{
ofstream file( "flight in formati on. txt" , ios::tru nc);
if (!file)
{
cerr << "ÎÄ¼þ\"flight information.txt\"	ÎÞ·¨´ò¿ª£¡ \n";
exit(2);
}
×¨Òµ×ÊÁÏ
int i = -1;
while (++i < m_sum)
{
if (!v_array[i].lf_deleted())
{
file << v_array[i];
}
}
file.close();
}
//¹ÜÀíº½°àÐÅÏ¢
void Traffic_system::Ma nage()
{
char password[20];¡¨	ÓÃÓÚ´æÖüÃÜÂë
int times = 3;
cout << "µÇÂ¼ÏµÍ³ÐèÑéÖ¤ÃÜÂë£¡	" << endl;
//ÑéÖ¤ÃÜÂë¡£Èý´Î´íÎóºó£¬¾Í×Ô¶¯ÍË³ö³ÌÐò
do
{
times--;
cout << "ÇëÊäÈëÃÜÂë£º(Ä¬ÈÏ000)";
cin >> password;
if(strcmp(password, "000") == 0)//	ÃÜÂëÊÇ¡° 000 ¡±
{
times = -1;
break;
}
else if (times > 0)
cout << "	ÃÜÂë´íÎó!\n Ê£Óà"<< times << "´Î»ú»á!" << endl;
}while(times > 0);
if(times != -1)
{
cout << "¶Ô²»Æð!\nÄú²»ÊÇ¹ÜÀíÔ±£¡²»ÄÜÊ¹ÓÃ´ËÏµÍ³!" << endl; return;

system("cls"); while (1)
{
int tab;


cout
<<
»¶Ó­Ê¹ÓÃº½°àÐÅ
Ï¢¹ÜÀíÏµÍ³
************************
**\n"




<<
II
	II
<< "\t**\t	>>1	ÖØÐÂ´´½¨ÐÅÏ¢¿â\t\t >>2 ¡ª
**\n\t**\t	>>3 ¡ª¡ªÐÞ¸ÄÐÅÏ¢\t\t	>>4 ¡ª¡ªÉ¾³ýÐÅÏ¢	**\n\t**\t
È«²¿\t\t >>0¡ª¡ªÍË³ö¹ÜÀí	**\n"
<<
II
<< "ÄãÐèÒª×öÊ²Ã´£¿(Ñ¡Ôñ 0~5)" << endl;
cin >> tab;
while(!(tab == 1 || tab == 2 || tab == 3 || tab == 4 || tab == 5 || tab ==0))
{
cout << "ÇëÊäÈëÕýÈ·Ñ¡Ôñ(0~5)£º";
cin >> tab;
}
switch(tab)
{
case 1:
{
m_sum = 0;
Flight fly;
cout << "Çë½øÐÐÐÅÏ¢Â¼Èë¡£°´¡° +¡±½áÊø£¡ \n";
do
v_array.push_back(fly);¡¨
while (v_array[m_sum++].Setl nfo());
break;
}
case 2:
{
Read_file();
Flight fly;
cout << "Çë½øÐÐÐÅÏ¢Â¼Èë¡£°´¡° +¡±½áÊø£¡ \n";
do
v_array.push_back(fly);¡¨
while (v_array[m_sum++].Setl nfo());
break;
}
case 3:
{
char fnum[1][18];
Read_file();
cout << "ÇëÊäÈëÄúÒªÐÞ¸ÄÐÅÏ¢µÄº½°àºÅ£º";
cin >> fnum[0];
int i = 0;
for (; i < m_sum; i++)
{
if (v_array[i]¡¹f_match(fnum, '1'))
{
cout << "¸Ãº½°àµÄÔ­ÐÅÏ¢Îª£º\n"
<<
¡ª\n"
<< "Ø­º½°àºÅØ­ ÆðÊ¼Õ¾
µãÕ¾	Ø­Æð·ÉÊ±¼äØ­Æ±¼ÛØ­ÓàÆ±Ø­"
<<
¡ª\n";
v_array[i].Display();
cout << "ÇëÊäÈëÕýÈ·ÐÅÏ¢£¡	\n";
v_array[i].Setl nfo();
m_sum++;¡¨±£³Ö¼°×Üº½ÏßÊý²»±ä

break;
}
if (i == m_sum)
{
cout << "±§Ç¸£¡ÄúÒªÐÞ¸ÄµÄÐÅÏ¢²»´æÔÚ£¡	" << endl;
return;
} m_sum++;¡¨ break;
}
case 4: {
char fnum[1][18];
Flight empty;//ÉùÃ÷"¿Õ"¶ÔÏó£¬ÓÃÓÚÉ¾³ý Read_file();
cout << "ÇëÊäÈëÄúÒªÉ¾³ýº½°àµÄº½°àºÅ£º
cin >> fnum[0];
int i = 0;
for (; i < m_sum; i++)
{
if (v_array[i]¡¹f_match(fnum, '1'))
{
cout << "ÄúÒªÉ¾³ýµÄº½°àÎª£º\n
<<
<< "Iº½°àºÅØ­
IÆð·ÉÊ±¼äØ­Æ±¼ÛØ­ÓàÆ±I "
<<



}
}
//ä¯ÀÀ void Traffic_system::Sca n()
char c;
Read_file();
if (m_sum == 0)
{
×¨Òµ×ÊÁÏ

cout << "ÔÝÎÞÐÅÏ¢£¡ÇëµÈ´ý¹ÜÀíÈËÔ±¸üÐÂ!
return;
}
cout << "\t º½°àÐÅÏ¢±í£º\n"
<<
¡ª\n"
<< "Ø­º½°àºÅØ­ ÆðÊ¼Õ¾	Ø­ ÖÕµãÕ¾
¼äØ­Æ±¼ÛØ­ÓàÆ±Ø­"
<<
¡ª\n";
for (int i = 0; i < m_sum; i++) v_array[i].Display();
cout << "°´ÈÎÒâ¼ü·µ»ØÖ÷²Ëµ¥! cin >> c;
} //²éÑ¯¹¦ÄÜ
int Traffic_system::Search(i nt inv oke)
{
int tab;
Read_file();
cout
"*************************************************************************\n***
¡ª¡ª°´º½°àºÅ²éÑ¯	>>2¡ª¡ª°´Õ¾µã²éÑ¯	>>0
***¡¢n*************************************************************************\n
(0~2)£º"
<< en dl;
cin >> tab;
while(!(tab == 1 || tab == 2 || tab == 0))
{
cout << "ÇëÊäÈëÕýÈ·Ñ¡Ôñ(0~2)£º";
cin >> tab;
}
×¨Òµ×ÊÁÏ


char str[2][18], ta;
if (tab == 0)
return -1;
else if (tab == 1)
{
cout << "ÇëÊäÈëº½°àºÅ£º";
cin >> str[0];
ta = '1';
}
else
{
cout << "ÇëÊäÈë³ö·¢Õ¾£º";
cin >> str[0];
cout << "ÇëÊäÈëÖÕµãÕ¾£º";
cin >> str[1];
ta = 2;
}
for (int i = 0; i < m_sum; i++)
{
if (v_array[i]¡¹f_match(str, ta))
{
cout << "ÄúÒª²éÑ¯µÄ½á¹ûÈçÏÂ£º\n"
<<
¡ª\n"
<< "Iº½°àºÅ Ø­
Ø­Æð·ÉÊ±¼äØ­Æ±¼ÛØ­ÓàÆ±I "
<<
II
<< en dl; v_array[i].Display(); if (inv oke == 0) {
cout << "°´ÈÎÒâ¼ü·µ»ØÖ÷²Ëµ¥!
char c; cin >> c;
}
return i;
}
}
cout << "±§Ç¸£¡Äú²éÑ¯µÄº½°à²»´æÔÚ£¡	" << endl;
return -1;
} //¶©Æ±ºÍÍËÆ±
void Traffic_system::BookRefu nd() {
while (1)
{
cout
»¶Ó­½øÈë»úÆ±·þÎñÏµ



en dl;
int tab;
cin >> tab;
while(!(tab == 1 || tab == 2 || tab == 0))
{
cout << "ÇëÊäÈëÕýÈ·Ñ¡Ôñ(0~2)£º" cin >> tab;
}
char ta;
switch(tab)
{
case 1:
{
cout << "ÇëÏÈ²éÕÒ¸Ãº½°à£º"<< endl;
int i;
i = Search(1);
if (i != -1 && v_array[i].Book())
{
cout << "¡¶È·ÈÏ¶©Æ±\\Y¡·	¡¶È¡Ïû¶©Æ±\\N¡·\nÇëÑ¡Ôñ£º"£»
do
{
cin >> ta;
}while(!(ta == 'Y' || ta == 'y' || ta == 'N' || ta == 'n'));
if(ta == 'Y' || ta == 'y')
{
Save_file();
cout << "¶©Æ±³É¹¦£¡ " << endl;
}
}
break;
}
case 2:
{
char str[1][18];
Read_file();
cout << "ÇëÊäÈëº½°àºÅ£º";
cin >> str[0];
int i = 0;
for (; i < m_sum; i++)
{
if (v_array[i]¡¹f_takeoff())
con ti nue;
if (v_array[i]¡¹f_match(str, '1'))
{
v_array[i].Refu nd();
cout << "¡¶È·ÈÏÍËÆ±\\Y¡·	¡¶È¡ÏûÍËÆ±\\N¡·\nÇëÑ¡Ôñ£º"

do
{
cin >> ta;
}while(!(ta == 'Y' || ta == 'y' || ta == 'N' || ta == 'n'));
if(ta == 'Y' || ta == 'y')
{
Save_file();
cout << "ÍËÆ±³É¹¦£¡ " << endl;
}
break;
}
}
if (i == m_sum)
{
cout << "²»´æÔÚ¸Ãº½°à»ò¸Ãº½°àÒÑÆð·É£¡²»ÄÜÍËÆ±¡£	"<< endl;
break;
}
}
case 0:return;
}
}
}
ÎÄ¼þ	class/ flight.h
class Flight
{
public:
Flight()
{
m_fnum[0] = '+';
}
bool SetI nfo();¡¨ ÉèÖÃº½°àÐÅÏ¢
frie nd istrea m& operator?(istream& in, Flight & cp);¡¨
frie nd ostream& operator<<(ostream& out, Flight& cp);¡¨
void Display¡£;//	Êä³öº½°àÐÅÏ¢
bool Book();¡¨ ¶©Æ±
void Refu nd();¡¨ ÍËÆ±
bool lf_takeoff();¡¨ ÅÐ¶ÏÊÇ·ñÆð·É
bool If_deleted();//	ÅÐ¶ÏÊÇ·ñÉ¾³ý
bool lf_match(char (*p)[18], char ta);//	ÅÐ¶Ïº½°àºÅ»òÕ¾µãÃûÊÇ·ñÏàÍ¬
private:
char m_fnum[10];¡¨	º½°àºÅ
int m_ftime[2];¡¨	Æð·ÉÊ±¼ä
char m_fstar[18];¡¨	ÆðÊ¼Õ¾
char m_fdest in atio n[ 18];//	ÖÕµãÕ¾
int m_fprice;// Æ±¼Û
int m_fseat;¡¨ Æ±Êý
};
ÎÄ¼þ	class/ flight.cpp
#i nclude <iostream>
#in clude <stri ng>
#i nclude <ioma nip>
#i nclude <ctime>//time.h in C
using n amespace std;
#include <stdio.h>
#include "flight.h"
//<<ÔËËã·ûÖØÔØ
istream& operator?(istream& in, Flight& cp)
{
in >> cp.m_f num >> cp.m_fstar >> cp.m_fdesti natio n >> cp.m_ftime[0] >> cp.m_ftime[1] >> cp.m_fprice >> cp.m_fseat;
return in;
ostream& operator?(ostream& out, Flight& cp)
{
out << cp.m_f num << " " << cp.m_fstar << " " << cp.m_fdesti nati on << "" << cp.m_ftime[O] << " " << cp.m_ftime[1] << ""<< cp.m_fprice << " " << cp.m_fseat << "\n";
return out;
}
//»ñÈ¡ÏµÍ³Ê±¼ä
int get_systemtime()
{
time_t now;
struct tm *fmt;
time(&no w);
fmt = localtime(&no w);
return (fmt->tm_hour * 60 + fmt->tm_mi n);
}
//ÅÐ¶ÏÊÇ·ñÆð·É
bool Flight::lf_takeoff()
{
return (m_ftime[0] * 60 + m_ftime[1] <= get_systemtime());
}
//ÅÐ¶ÏÊÇ·ñ×÷·Ï
bool Flight::lf_deleted()
{
retur n m_fnum[0]=='-';
}
//ÅÐ¶Ïº½°àºÅ»òÕ¾µãÃûÊÇ·ñÏàÍ¬
bool Flight::lf_match(char (*p)[18], char ta)
{
if (ta == '1')
return (!strcmp(m_fnum, p[0]));
else
return (!strcmp(m_fstar, p[0]) && !strcmp(m_fdestination, p[1]));
//ÉèÖÃº½°àÐÅÏ¢
bool Flight::Setl nfo()
{
cout << "ÊäÈëº½°àºÅ£º";
cin >> m_fnum;
if (m_fnum[0] == '+')
return false;
cout << "ÆðÊ¼Õ¾£º";
cin >> m_fstar;
cout << "ÖÕµãÕ¾£º";
cin >> m_fdesti nati on;
cout << "ÇëÊäÈëÆð·ÉÊ±¼ä£º(¸ñÊ½£º03:05)"
scan f("%d:%d",m_ftime, m_ftime + 1);
cout << "Æ±¼Û£º";
cin >> m_fprice;
cout << "ÓàÆ±£º";
cin >> m_fseat;
return true;
} //Êä³öº½°àÐÅÏ¢
void Flight::Display()
{
if (If_takeoff())
{
cout << " I " << setiosflags(ios::left) << setw(10) << m_fnum << "	I " <<
setw(18) << m fstar << " I " << setw(18) << m_fdest in ati on
<< "I " << "±¾´Îº½°àÒÑ¾­Æð·É£¡	" << " I "


} else
{
cout << " I " << setiosflags(ios::left) << setw(10) << m_fnum << "	I " <<
setw(18) << m fstar << " I " << setw(18) << m_fdest in ati on
<< "I " << setiosflags(ios::right) << setw(2) << setfill('0') << m_ftime[0]
<< ":"<< setw (2) << m_ftime[1] << setfill('')
<< " I " << setw(4) << m_fprice << " I " << setw(5) << m_fseat << "
I " << resetiosflags(ios::right)
<<
	II
} } //¶©Æ± bool Flight::Book()
{
if (If_takeoff())
{
cout << "¸Ãº½°àÒÑ¾­Æð·É£¬Í£Ö¹ÊÛÆ±£¡	" << en dl;
return false;
}
int count;
cout << "ÇëÊäÈë¶©¹ºµÄÆ±Êý£º";
cin >> count;
if (m_fseat < count)
{
cout << "ÓàÆ±²»×ã£¡ " << endl; return false;
}
m_fseat -= count;
return true;

//ÍËÆ±
void Flight::Refu nd()
{
if (If_takeoff())
{
cout << "¸Ãº½°àÒÑ¾­Æð·É£¬Í£Ö¹ÍËÆ±! return;
}
int count;
cout << "ÇëÊäÈëÍË¶©Æ±Êý";
cin >> count;
m_fseat += count;
}