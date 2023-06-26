 #include <iostream>
 #include <iomanip>
 #include <conio.h>
 #include <string>

using namespace std;

struct data
{
    string provinsi, kota;
    double totalPenduduk, totalLansia, totalPendudukV, totalLansiaV, pendudukP, lansiaP; //V = sudah vaksin P = persen
    int level;
};


int main()
{
    int jumlahData, i, urut, x, y, templ, temptp, temptl, temptpv, temptlv, item, lvl, kiri, kanan, tengah;
    string tempp, tempk,prov,kota;
    double pendudukP,lansiaP;
    char ulang;

    do
    {

    system ("cls");

    cout << "\t\t\t\t\t\t *******************************" << endl;
    cout << "\t\t\t\t\t\t |PROGRAM MENENTUKAN LEVEL PPKM|" << endl;
    cout << "\t\t\t\t\t\t *******************************" << endl;

    data wilayah [10] =
    { {"Aceh","Sabang", 42550, 1740, 37890, 1490},
    {"Sumatera Barat","Sijunjung", 121020, 39280, 80420, 28880},
    {"Jambi","Batanghari", 1686070, 592220, 903670, 29780},
    {"Gorontalo","Gorontalo Utara", 1600000, 440250, 786000, 214540},
    {"Jawa Tengah","Kebumen", 1361910, 401050, 896230, 321430},
    {"Jawa Timur","Surabaya", 2880280, 2105000, 2001900, 1005900},//baru kuganti total lansia, blom di cek manual untuk level
    {"Kalimantan Selatan","Banjarmasin", 662230, 215890, 250980, 50300},
    {"Sulawesi Selatan","Toraja Utara", 1427610, 453900, 729200, 339750},
    {"Bengkulu","Kaur", 453180, 78090, 200450, 25080},
    {"Maluku","Ambon", 347660, 78560, 210400, 65430} };

    jumlahData = sizeof (wilayah)/sizeof(wilayah[0]);

    //menentukan level wilayah
    for (i=0; i<jumlahData; i++)
    {
        wilayah[i].pendudukP = ((wilayah[i].totalPendudukV/wilayah[i].totalPenduduk)*100);
        wilayah[i].lansiaP = ((wilayah[i].totalLansiaV/wilayah[i].totalLansia)*100);

        if(wilayah[i].pendudukP >= 70 && wilayah[i].lansiaP >= 60)
        {
            wilayah[i].level = 1;
        }else if (wilayah[i].pendudukP >= 50  && wilayah[i].lansiaP >= 40 )
        {
            wilayah[i].level = 2;
        }else if (wilayah[i].pendudukP < 50 || wilayah[i].lansiaP < 60)
        {
            wilayah[i].level = 3;
        }
    }

    //output data wilayah
    cout <<"============================================================================================================================================="<< endl;
    cout <<"| No |       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
    cout <<"============================================================================================================================================="<< endl;

    for (i=0; i<jumlahData;i++)
    {
        cout <<"|"<<setw(4)<<i+1;
        cout <<"|"<<setw(22)<<wilayah[i].provinsi;
        cout <<"|"<<setw(18)<<wilayah[i].kota;
        cout <<"|"<<setw(18)<<wilayah[i].totalPenduduk;
        cout <<"|"<<setw(16)<<wilayah[i].totalLansia;
        cout <<"|"<<setw(21)<<wilayah[i].totalPendudukV;
        cout <<"|"<<setw(19)<<wilayah[i].totalLansiaV;
        cout <<"|"<<setw(14)<<wilayah[i].level<<"|";
        cout << endl;
    }
    cout <<"============================================================================================================================================"<< endl;
    cout <<"next ->";
    getch();

    //insertion sort
    do
    {
        system("cls");
        cout << "1.Ascending 2.Descending " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Urutkan data berdasarkan Level PPKM (1/2) : ";cin >> urut;

        if (urut == 1)
        {
            for (x=1; x<jumlahData; x++)
            {

                for (y=x; y>0; y--)
                {
                    if (wilayah[y].level < wilayah[y-1].level)
                    {
                        templ = wilayah[y].level;
                        wilayah[y].level = wilayah[y-1].level;
                        wilayah[y-1].level = templ;

                        tempp = wilayah[y].provinsi;
                        wilayah[y].provinsi = wilayah[y-1].provinsi;
                        wilayah[y-1].provinsi = tempp;

                        tempk = wilayah[y].kota;
                        wilayah[y].kota = wilayah[y-1].kota;
                        wilayah[y-1].kota = tempk;

                        temptp = wilayah[y].totalPenduduk;
                        wilayah[y].totalPenduduk = wilayah[y-1].totalPenduduk;
                        wilayah[y-1].totalPenduduk = temptp;

                        temptl = wilayah[y].totalLansia;
                        wilayah[y].totalLansia = wilayah[y-1].totalLansia;
                        wilayah[y-1].totalLansia = temptl;

                        temptpv = wilayah[y].totalPendudukV;
                        wilayah[y].totalPendudukV = wilayah[y-1].totalPendudukV;
                        wilayah[y-1].totalPendudukV = temptpv;

                        temptlv = wilayah[y].totalLansiaV;
                        wilayah[y].totalLansiaV = wilayah[y-1].totalLansiaV;
                        wilayah[y-1].totalLansiaV = temptlv;

                    }else
                    {
                        break;
                    }
                }
            }
        }else if (urut == 2 )
        {
            for (x=1; x<jumlahData; x++)
            {
                for (y=x; y>0; y--)
                {
                    if (wilayah[y].level > wilayah[y-1].level)
                    {
                        templ = wilayah[y].level;
                        wilayah[y].level = wilayah[y-1].level;
                        wilayah[y-1].level = templ;

                        tempp = wilayah[y].provinsi;
                        wilayah[y].provinsi = wilayah[y-1].provinsi;
                        wilayah[y-1].provinsi = tempp;

                        tempk = wilayah[y].kota;
                        wilayah[y].kota = wilayah[y-1].kota;
                        wilayah[y-1].kota = tempk;

                        temptp = wilayah[y].totalPenduduk;
                        wilayah[y].totalPenduduk = wilayah[y-1].totalPenduduk;
                        wilayah[y-1].totalPenduduk = temptp;

                        temptl = wilayah[y].totalLansia;
                        wilayah[y].totalLansia = wilayah[y-1].totalLansia;
                        wilayah[y-1].totalLansia = temptl;

                        temptpv = wilayah[y].totalPendudukV;
                        wilayah[y].totalPendudukV = wilayah[y-1].totalPendudukV;
                        wilayah[y-1].totalPendudukV = temptpv;

                        temptlv = wilayah[y].totalLansiaV;
                        wilayah[y].totalLansiaV = wilayah[y-1].totalLansiaV;
                        wilayah[y-1].totalLansiaV = temptlv;

                    }else
                    {
                        break;
                    }
                }
            }
        }

    cout << "Masukkan angka yang tepat !"<< endl;

    }while(urut != 1 && urut != 2);

    system("cls");

    //output data wilayah setelah sorting berdasarkan level
    cout <<"============================================================================================================================================="<< endl;
    cout <<"| No |       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
    cout <<"============================================================================================================================================="<< endl;

    for (i=0; i<jumlahData; i++)
    {
        cout <<"|"<<setw(4)<<i+1;
        cout <<"|"<<setw(22)<<wilayah[i].provinsi;
        cout <<"|"<<setw(18)<<wilayah[i].kota;
        cout <<"|"<<setw(18)<<wilayah[i].totalPenduduk;
        cout <<"|"<<setw(16)<<wilayah[i].totalLansia;
        cout <<"|"<<setw(21)<<wilayah[i].totalPendudukV;
        cout <<"|"<<setw(19)<<wilayah[i].totalLansiaV;
        cout <<"|"<<setw(14)<<wilayah[i].level<<"|";
        cout << endl;
    }
    cout <<"============================================================================================================================================"<< endl;
    cout <<"next ->";
    getch();

    //binary search
    do
    {
        system ("cls");

        cout << "1.Level PPKM 2.Provinsi 3.Kota/Kabupaten" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Pencarian data berdasarkan item (1/2/3) : ";cin >> item;

        system("cls");

        switch (item)
        {
            case 1:
            cout << "Masukkan level PPKM : ";cin>>lvl;
            system ("cls");
            cout <<"========================================================================================================================================"<< endl;
            cout <<"|       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
            cout <<"========================================================================================================================================"<< endl;

            i=0;
            do
            {
                kiri = 0;
                kanan = jumlahData-1;

                while (kiri <= kanan)
                {
                    tengah = (kiri+kanan)/2;
                    if (lvl == wilayah[i].level)
                    {
                        cout <<"|"<<setw(22)<<wilayah[i].provinsi;
                        cout <<"|"<<setw(18)<<wilayah[i].kota;
                        cout <<"|"<<setw(18)<<wilayah[i].totalPenduduk;
                        cout <<"|"<<setw(16)<<wilayah[i].totalLansia;
                        cout <<"|"<<setw(21)<<wilayah[i].totalPendudukV;
                        cout <<"|"<<setw(19)<<wilayah[i].totalLansiaV;
                        cout <<"|"<<setw(14)<<wilayah[i].level<<"|";
                        cout << endl;

                        break;

                    }else if (lvl > wilayah[i].level)
                    {
                        kiri = tengah+1;
                    }else
                    {
                        kanan = tengah-1;
                    }
                }

                i++;

            }while (i<jumlahData);

            cout <<"========================================================================================================================================"<< endl;
            break;

            case 2:
            //urutin data berdasarkan  provinsi  (asc)
            for (x=1; x<jumlahData; x++)
            {
                for (y=x; y>0; y--)
                {
                    if (wilayah[y].provinsi < wilayah[y-1].provinsi)
                    {
                        templ = wilayah[y].level;
                        wilayah[y].level = wilayah[y-1].level;
                        wilayah[y-1].level = templ;

                        tempp = wilayah[y].provinsi;
                        wilayah[y].provinsi = wilayah[y-1].provinsi;
                        wilayah[y-1].provinsi = tempp;

                        tempk = wilayah[y].kota;
                        wilayah[y].kota = wilayah[y-1].kota;
                        wilayah[y-1].kota = tempk;

                        temptp = wilayah[y].totalPenduduk;
                        wilayah[y].totalPenduduk = wilayah[y-1].totalPenduduk;
                        wilayah[y-1].totalPenduduk = temptp;

                        temptl = wilayah[y].totalLansia;
                        wilayah[y].totalLansia = wilayah[y-1].totalLansia;
                        wilayah[y-1].totalLansia = temptl;

                        temptpv = wilayah[y].totalPendudukV;
                        wilayah[y].totalPendudukV = wilayah[y-1].totalPendudukV;
                        wilayah[y-1].totalPendudukV = temptpv;

                        temptlv = wilayah[y].totalLansiaV;
                        wilayah[y].totalLansiaV = wilayah[y-1].totalLansiaV;
                        wilayah[y-1].totalLansiaV = temptlv;
                    }
                }
            }

            cout <<"========================================================================================================================================"<< endl;
            cout <<"|       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
            cout <<"========================================================================================================================================"<< endl;

            for (i=0; i<jumlahData;i++)
            {
                cout <<"|"<<setw(22)<<wilayah[i].provinsi;
                cout <<"|"<<setw(18)<<wilayah[i].kota;
                cout <<"|"<<setw(18)<<wilayah[i].totalPenduduk;
                cout <<"|"<<setw(16)<<wilayah[i].totalLansia;
                cout <<"|"<<setw(21)<<wilayah[i].totalPendudukV;
                cout <<"|"<<setw(19)<<wilayah[i].totalLansiaV;
                cout <<"|"<<setw(14)<<wilayah[i].level<<"|";
                cout << endl;
            }
            cout <<"========================================================================================================================================"<< endl << endl;
            cout << "Masukkan Nama Provinsi : ";
            getline (cin>>ws, prov);

            system("cls");

            cout <<"========================================================================================================================================"<< endl;
            cout <<"|       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
            cout <<"========================================================================================================================================"<< endl;

            kiri = 0;
            kanan = jumlahData-1;

            while (kiri <= kanan)
            {
                tengah = (kiri+kanan)/2;

                if (prov == wilayah[tengah].provinsi)
                {
                    cout <<"|"<<setw(22)<<wilayah[tengah].provinsi;
                    cout <<"|"<<setw(18)<<wilayah[tengah].kota;
                    cout <<"|"<<setw(18)<<wilayah[tengah].totalPenduduk;
                    cout <<"|"<<setw(16)<<wilayah[tengah].totalLansia;
                    cout <<"|"<<setw(21)<<wilayah[tengah].totalPendudukV;
                    cout <<"|"<<setw(19)<<wilayah[tengah].totalLansiaV;
                    cout <<"|"<<setw(14)<<wilayah[tengah].level<<"|";
                    cout << endl;

                    break;

                }else if (prov > wilayah[tengah].provinsi)
                {
                    kiri = tengah+1;
                }else
                {
                    kanan = tengah-1;
                }

            }

            cout <<"========================================================================================================================================"<< endl;

            break;

            case 3:
            //urutin data berdasarkan  kota/kabupaten  (asc)
            for (x=1; x<jumlahData; x++)
            {
                for (y=x; y>0; y--)
                {
                    if (wilayah[y].kota < wilayah[y-1].kota)
                    {
                        templ = wilayah[y].level;
                        wilayah[y].level = wilayah[y-1].level;
                        wilayah[y-1].level = templ;

                        tempp = wilayah[y].provinsi;
                        wilayah[y].provinsi = wilayah[y-1].provinsi;
                        wilayah[y-1].provinsi = tempp;

                        tempk = wilayah[y].kota;
                        wilayah[y].kota = wilayah[y-1].kota;
                        wilayah[y-1].kota = tempk;

                        temptp = wilayah[y].totalPenduduk;
                        wilayah[y].totalPenduduk = wilayah[y-1].totalPenduduk;
                        wilayah[y-1].totalPenduduk = temptp;

                        temptl = wilayah[y].totalLansia;
                        wilayah[y].totalLansia = wilayah[y-1].totalLansia;
                        wilayah[y-1].totalLansia = temptl;

                        temptpv = wilayah[y].totalPendudukV;
                        wilayah[y].totalPendudukV = wilayah[y-1].totalPendudukV;
                        wilayah[y-1].totalPendudukV = temptpv;

                        temptlv = wilayah[y].totalLansiaV;
                        wilayah[y].totalLansiaV = wilayah[y-1].totalLansiaV;
                        wilayah[y-1].totalLansiaV = temptlv;
                    }
                }
            }

            cout <<"========================================================================================================================================"<< endl;
            cout <<"|       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
            cout <<"========================================================================================================================================"<< endl;

            for (i=0; i<jumlahData;i++)
            {
                cout <<"|"<<setw(22)<<wilayah[i].provinsi;
                cout <<"|"<<setw(18)<<wilayah[i].kota;
                cout <<"|"<<setw(18)<<wilayah[i].totalPenduduk;
                cout <<"|"<<setw(16)<<wilayah[i].totalLansia;
                cout <<"|"<<setw(21)<<wilayah[i].totalPendudukV;
                cout <<"|"<<setw(19)<<wilayah[i].totalLansiaV;
                cout <<"|"<<setw(14)<<wilayah[i].level<<"|";
                cout << endl;
            }
            cout <<"========================================================================================================================================="<< endl << endl;
            cout << "Masukkan Nama Kota/Kabupaten : ";
            getline (cin>>ws, kota);

            system("cls");

            cout <<"========================================================================================================================================"<< endl;
            cout <<"|       Provinsi       |  Kota/Kabupaten  |  Total Penduduk  |  Total Lansia  |  Total Penduduk(V)  |  Total Lansia(V)  |  Level PPKM  |"<< endl;
            cout <<"========================================================================================================================================"<< endl;

            kiri = 0;
            kanan = jumlahData-1;

            while (kiri <= kanan)
            {
                tengah = (kiri+kanan)/2;
                if (kota == wilayah[tengah].kota)
                {
                    cout <<"|"<<setw(22)<<wilayah[tengah].provinsi;
                    cout <<"|"<<setw(18)<<wilayah[tengah].kota;
                    cout <<"|"<<setw(18)<<wilayah[tengah].totalPenduduk;
                    cout <<"|"<<setw(16)<<wilayah[tengah].totalLansia;
                    cout <<"|"<<setw(21)<<wilayah[tengah].totalPendudukV;
                    cout <<"|"<<setw(19)<<wilayah[tengah].totalLansiaV;
                    cout <<"|"<<setw(14)<<wilayah[tengah].level<<"|";
                    cout << endl;

                    break;

                }else if (kota > wilayah[tengah].kota)
                {
                    kiri = tengah+1;
                }else
                {
                    kanan = tengah-1;
                }

            }

            cout <<"========================================================================================================================================"<< endl;
            break;

            default:
            cout << "Masukkan angka yang tepat !"<< endl;
            break;

        }

        getch();

    }while (item != 1 && item != 2 && item != 3);

    cout << "Apakah Anda mau mengulang (Y/T) :";cin>>ulang;

    }while (ulang == 'y' || ulang == 'Y');

    return 0;
}
