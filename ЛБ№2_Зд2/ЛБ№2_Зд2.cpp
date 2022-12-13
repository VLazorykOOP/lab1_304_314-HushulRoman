#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    char so[128];
    char S[128];
    unsigned short Rez[128];
    ifstream ifs("D:\\inlb2.dat.txt");
    if (!ifs) {
        cout << "File inlb2.dat not open" << endl; return -1;
    }
    ofstream ofs("D:\\outlb2.dat.txt");
    ofstream ofsb("D:\\outblb2.dat.txt", ios::out | ios::binary);
    unsigned char c;
    unsigned short r, t, i, b, tt, w, low;
    short j;
    for (i = 0; i < 128; i++)
    {
        r = 0;
        c = S[i];
        t = c;
        r |= t >> 4;
        r |= i << 4;
        t = c;
        r |= t << 11;
        t = 1;
        b = 0;
        for (j = 0; j < 16; j++)
        {
            if (r & t)
            {
                if (b == 0) b = 1;
                else b = 0;
            }
            t <<= 1;
        }
        r |= b << 15;
        Rez[i] = r;
        ofs << hex << Rez[i] << ' ';
    }
    ofsb.write((char*)S, 128 * sizeof(unsigned short));
    ofsb.close();
    ifs.close();
    ifs.open("D:\\outblb2.dat.txt", ios::in | ios::binary);
    ifs.read((char*)Rez, 128 * sizeof(unsigned short));
    short indi, indj;
    for (int i = 0; i < 128; i++)
    {
        r = Rez[i];
        tt = r & 0x000f;
        indj = r & 0x07f0;
        indj = indj >> 4;
      
        low = r & 0x7800;
        low = low >> 11;
        tt = tt << 4;
        tt = tt | low;
   
        so[indj] = tt;
    }
    for (int i = 0; i < 128; i++)
    {
        cout << so[i] << " ";
    }
    return 0;
}