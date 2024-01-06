#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_pasien{
	char kode[12];
	char nama[50];
	char pekerjaan[50];
	char nohp[50];
	char umur[4];
	char pj[50];
	char diagnosa[400];
};
typedef struct data_pasien dp;

struct waktu
{
	int tanggal;
	int bulan;
	int tahun;
};
typedef struct waktu wkt;

struct biaya
{
	int obat;
	int operasi;
	int total;
};
typedef struct biaya bea;

struct rekam_medis{
	struct data_pasien dp;
	char anamnesis[500];
	char proseduroperasi[500];
	char postoperasi[500];
	char medicalcheckup[500];
	struct biaya bea;
	struct waktu wkt;
};
typedef struct rekam_medis remed;

struct user{
    char username[50];
    char password[50];
};

 
remed data[50];

void tambah();
void tampil();
void welcomescreen();
void swap(int *A, int *B);
void sorting_tanggal();
void sorting_nama();
void searchByTanggal();
void searchByNama();
int total(int x, int y);

int size=0,x;
void tambah(char kode[12],char nama[50],char pekerjaan[50], char nohp[50], char umur[4], char pj[50], char diagnosa[400], char anamnesis[500], char proseduroperasi[500], char postoperasi[500], char medicalcheckup[500]){
	strcpy(data[size].dp.kode,kode);
	strcpy(data[size].dp.nama,nama);
	strcpy(data[size].dp.pekerjaan,pekerjaan);
	strcpy(data[size].dp.nohp,nohp);
	strcpy(data[size].dp.umur,umur);
	strcpy(data[size].dp.pj,pj);
	strcpy(data[size].dp.diagnosa,diagnosa);
	strcpy(data[size].anamnesis,anamnesis);
	strcpy(data[size].proseduroperasi,proseduroperasi);
	strcpy(data[size].postoperasi,postoperasi);
	strcpy(data[size].medicalcheckup,medicalcheckup);
	printf("Harga Obat : ");
	scanf("%i", &data[size].bea.obat);
	printf("Biaya Operasi : ");
	scanf("%i", &data[size].bea.operasi);
	printf("Waktu Input : ");
	scanf("%i %i %i", &data[size].wkt.tanggal, &data[size].wkt.bulan, &data[size].wkt.tahun);
	size++;
}

void tampil(){
	int i;
	if(size>0){
		for(i=0;i<size;i++){
			x=strlen(data[i].dp.kode); //panjang dari string 
			if(x>=1){
			printf("\nIdentitas Pasien ke - [%d]\n",i);
			printf("Kode \t\t\t: %s\n",data[i].dp.kode);	
			printf("Nama \t\t\t: %s\n",data[i].dp.nama);
			printf("Pekerjaan \t\t: %s\n",data[i].dp.pekerjaan);
			printf("No HP \t\t\t: %s\n",data[i].dp.nohp);
			printf("Umur \t\t\t: %s\n",data[i].dp.umur);
			printf("Penanggung Jawab \t: %s\n",data[i].dp.pj);
			printf("Diagnosa \t\t: %s\n",data[i].dp.diagnosa);
			printf("Anamnesis \t\t: %s\n",data[i].anamnesis);	
			printf("Prosedur Operasi \t: %s\n",data[i].proseduroperasi);	
			printf("Post Operasi \t\t: %s\n",data[i].postoperasi);	
			printf("Medical Check Up \t: %s\n",data[i].medicalcheckup);	
			printf("Harga Obat \t\t: %i\n",data[i].bea.obat);	
			printf("Biaya Operasi \t\t: %i\n",data[i].bea.operasi);	
			data[i].bea.total = total(data[i].bea.obat,data[i].bea.operasi);
			printf("Total Biaya \t\t: %i\n",data[i].bea.total);	
			printf("Waktu Input \t\t: %i/%i/%i\n\n", data[i].wkt.tanggal, data[i].wkt.bulan, data[i].wkt.tahun);
			}
		}
	}
}

void welcomescreen()
{
    printf("\n\n\n\n\n\n\n#########################################################");
    printf("\n\t#\t\t Welcome To\t\t#");
    printf("\n\t#   RS KOTAKITA Rekam Medis System      #");
    printf("\n#########################################################");
    printf("\n\n\n Tekan apapun untuk lanjut.......\n");
    getch();  
    system("cls"); 
}

void endscreen(){
	printf("\n");
    printf("     ***    ***\n");
    printf("   ******* *******\n");
    printf(" ***************\n");
    printf("  *************\n");
    printf("   ***********\n");
    printf("    *********\n");
    printf("     *******\n");
    printf("      *****\n");
    printf("       ***\n");
    printf("        *\n\n");
	printf("\n Arroyyan Syahru Romadhoni Roziqi | 1202230005");
	printf("\n Ardy Ferdinand Christanto Mongdong | 1202230002");
}

void sorting_tanggal(){
	int pilih_sorting_tanggal;
    printf("Urutan:\n1. Ascending\n2. Descending\nPilih urutan: ");
    scanf("%i", &pilih_sorting_tanggal);
	int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (pilih_sorting_tanggal == 1) { // ascending
                if (data[j].wkt.tahun > data[j+1].wkt.tahun) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                } else if (data[j].wkt.tahun == data[j + 1].wkt.tahun && data[j].wkt.bulan > data[j + 1].wkt.bulan) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                } else if (data[j].wkt.tahun == data[j + 1].wkt.tahun && data[j].wkt.bulan == data[j + 1].wkt.bulan && data[j].wkt.tanggal > data[j + 1].wkt.tanggal) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            } else if (pilih_sorting_tanggal == 2) { // descending
                if (data[j].wkt.tahun < data[j+1].wkt.tahun) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                } else if (data[j].wkt.tahun == data[j + 1].wkt.tahun && data[j].wkt.bulan < data[j + 1].wkt.bulan) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                } else if (data[j].wkt.tahun == data[j + 1].wkt.tahun && data[j].wkt.bulan == data[j + 1].wkt.bulan && data[j].wkt.tanggal < data[j + 1].wkt.tanggal) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
	printf("Data setelah diurutkan berdasarkan Tanggal:\n");
    tampil();
}

void sorting_nama() {
    int pilih_sorting_nama;
    printf("Urutan:\n1. Ascending\n2. Descending\nPilih urutan: ");
    scanf("%i", &pilih_sorting_nama);
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (pilih_sorting_nama == 1) { // ascending
                if (strcmp(data[j].dp.nama, data[j + 1].dp.nama) > 0) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            } else if (pilih_sorting_nama == 2) { // descending
                if (strcmp(data[j].dp.nama, data[j + 1].dp.nama) < 0) {
                    struct rekam_medis temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
	printf("Data setelah diurutkan berdasarkan Nama:\n");
    tampil();
}

void searchByTanggal() {
	int tanggal, bulan, tahun;
    printf("Masukkan tanggal, bulan, tahun untuk pencarian: ");
    scanf("%d %d %d", &tanggal, &bulan, &tahun);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (data[i].wkt.tanggal == tanggal && data[i].wkt.bulan == bulan && data[i].wkt.tahun == tahun) {
            found = 1;
            printf("Data ditemukan pada indeks %d\n", i);
            printf("Kode \t\t\t: %s\n", data[i].dp.kode);
            printf("Nama \t\t\t: %s\n", data[i].dp.nama);
            printf("Pekerjaan \t\t: %s\n",data[i].dp.pekerjaan);
			printf("No HP \t\t\t: %s\n",data[i].dp.nohp);
			printf("Umur \t\t\t: %s\n",data[i].dp.umur);
			printf("Penanggung Jawab \t: %s\n",data[i].dp.pj);
			printf("Diagnosa \t\t: %s\n",data[i].dp.diagnosa);
			printf("Anamnesis \t\t: %s\n",data[i].anamnesis);	
			printf("Prosedur Operasi \t: %s\n",data[i].proseduroperasi);	
			printf("Post Operasi \t\t: %s\n",data[i].postoperasi);	
			printf("Medical Check Up \t: %s\n",data[i].medicalcheckup);	
			printf("Harga Obat \t\t: %i\n",data[i].bea.obat);	
			printf("Biaya Operasi \t\t: %i\n",data[i].bea.operasi);	
			data[i].bea.total = total(data[i].bea.obat,data[i].bea.operasi);
			printf("Total Biaya \t\t: %i\n",data[i].bea.total);	
			printf("Waktu Input \t\t: %i/%i/%i\n\n", data[i].wkt.tanggal, data[i].wkt.bulan, data[i].wkt.tahun);
            break;
        }
    }
    if (!found) {
        printf("Data tidak ditemukan untuk tanggal %d/%d/%d\n", tanggal, bulan, tahun);
    }
}

void searchByNama() {
	char namaCari[50];
    printf("Masukkan nama untuk pencarian: ");
    scanf("%s", namaCari);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(data[i].dp.nama, namaCari) == 0) {
            found = 1;
            printf("Data ditemukan pada indeks %d\n", i);
            printf("Kode\t\t\t: %s\n", data[i].dp.kode);
            printf("Nama\t\t\t: %s\n", data[i].dp.nama);
            printf("Pekerjaan \t\t: %s\n",data[i].dp.pekerjaan);
			printf("No HP \t\t\t: %s\n",data[i].dp.nohp);
			printf("Umur \t\t\t: %s\n",data[i].dp.umur);
			printf("Penanggung Jawab \t: %s\n",data[i].dp.pj);
			printf("Diagnosa \t\t: %s\n",data[i].dp.diagnosa);
			printf("Anamnesis \t\t: %s\n",data[i].anamnesis);	
			printf("Prosedur Operasi \t: %s\n",data[i].proseduroperasi);	
			printf("Post Operasi \t\t: %s\n",data[i].postoperasi);	
			printf("Medical Check Up \t: %s\n",data[i].medicalcheckup);	
			printf("Harga Obat \t\t: %i\n",data[i].bea.obat);	
			printf("Biaya Operasi \t\t: %i\n",data[i].bea.operasi);	
			data[i].bea.total = total(data[i].bea.obat,data[i].bea.operasi);
			printf("Total Biaya \t\t: %i\n",data[i].bea.total);	
			printf("Waktu Input \t\t: %i/%i/%i\n\n", data[i].wkt.tanggal, data[i].wkt.bulan, data[i].wkt.tahun);
            break;
        }
    }
    if (!found) {
        printf("Data tidak ditemukan untuk nama %s\n", namaCari);
    }
}

int total(int x, int y){
	int z;
	z = x + y;
	return z;
}


// fungsi untuk melakukan login
int login(char *username, char *password, char *role) {
    FILE *file = fopen("D:\\KULIAH 2023\\Semester 1\\Alpro\\PRAKTIKUM IS FUN\\Bismillah-Tubes\\login.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char temp_username[50], temp_password[50], temp_role[50];
        sscanf(line, "%49[^,],%49[^,],%49[^\n]", temp_username, temp_password, temp_role);

        if (strcmp(username, temp_username) == 0 && strcmp(password, temp_password) == 0) {
            strcpy(role, temp_role);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


int main(){

	welcomescreen();

    char username[50], password[50], role[50];

	login:
	printf("Menu Login:\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (login(username, password, role)) {
        printf("Login Sukses!\n");
		goto awal;
    } else {
        printf("Login gagal. Invalid username or password.\n");
		goto login;
    }

	size = sizeof(remed)/sizeof(data[0]);
	int i=1;
	int pilih=0,pilih_edit;
	char kode[12],nama[50],pekerjaan[50],nohp[14],umur[4],pj[50],diagnosa[400];
	char anamnesis[500],proseduroperasi[500],postoperasi[500],medicalcheckup[500];
	awal:
	printf("====== Data Pasien ======\n");
	printf("Menu :\n1. Tampil Data\n2. Tambah Data\n3. Update Data\n4. Hapus Data\n5. Pengurutan Data\n6. Mencari Data\n7. Keluar\nPilih menu : ");
	scanf("%d",&pilih);
	if(pilih==1){
		printf("List Data Pasien: \n\n");
		tampil();
		printf("\nTekan sembarang tombol untuk lanjut");
		getch();
		system("cls");
		goto awal;
	}
	else if(pilih==2){
		printf("\nkode : ");
		scanf("%s",&kode);
		printf("Nama : ");
		scanf(" %[^\n]s",&nama);
		printf("pekerjaan : ");
		scanf(" %[^\n]s",&pekerjaan);
		printf("No HP : ");
		scanf("%s",&nohp);
		printf("Umur : ");
		scanf("%s",&umur);
		printf("Penanggung Jawab : ");
		scanf(" %[^\n]s",&pj);
		printf("Diagnosa : ");
  	    scanf(" %[^\n]s",&diagnosa);
		printf("Anamnesis : ");
  	    scanf(" %[^\n]s",&anamnesis);
		printf("Prosedur Operasi : ");
  	    scanf(" %[^\n]s",&proseduroperasi);
		printf("Post Operasi : ");
  	    scanf(" %[^\n]s",&postoperasi);
		printf("Medical Check Up : ");
  	    scanf(" %[^\n]s",&medicalcheckup);
		tambah(kode,nama,pekerjaan,nohp,umur,pj,diagnosa,anamnesis,proseduroperasi,postoperasi,medicalcheckup);
		printf("\nData Berhasi Ditambahkan!");
		getch();
		system("cls");
		goto awal;	
	}else if(pilih==3){
		int no;
		tampil();
		printf("Masukkan nomor data Pasien ke-[x] yang ingin diedit : ");
		inputedit:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data Pasien nomor ke %i, mohon masukkan nomor kembali : ", no);
			goto inputedit;
		}else{
			system("cls");
			printf("======Pengeditan Data Pasien======");
			printf("\nkode \t\t\t: %s\n",data[no].dp.kode);	
			printf("Nama \t\t\t: %s\n",data[no].dp.nama);
			printf("pekerjaan \t\t: %s\n",data[no].dp.pekerjaan);
			printf("No HP \t\t\t: %s\n",data[no].dp.nohp);
			printf("Umur \t\t\t: %s\n",data[no].dp.umur);
			printf("Penanggung Jawab \t: %s\n",data[no].dp.pj);
			printf("diagnosa \t\t: %s\n",data[no].dp.diagnosa);
			printf("Anamnesis \t\t: %s\n",data[no].anamnesis);	
			printf("Prosedur Operasi \t: %s\n",data[no].proseduroperasi);	
			printf("Post Operasi \t\t: %s\n",data[no].postoperasi);	
			printf("Medical Check Up \t: %s\n",data[no].medicalcheckup);
			printf("Harga Obat \t\t: %i\n",data[no].bea.obat);	
			printf("Biaya Operasi \t\t: %i\n",data[no].bea.operasi);	
			printf("Waktu Input \t\t: %i/%i/%i\n\n", data[no].wkt.tanggal, data[no].wkt.bulan, data[no].wkt.tahun);
			printf("\nPilih data yang ingin diedit sesuai nomor (1.Kode;2.Nama;3.Pekerjaan;4.No Hp;5.Umur;6.Penanggung Jawab;7.Diagnosa;8.Anamnesis;9.Prosedur Operasi;10.Post Operasi;11.Medical Check Up;12.Harga Obat;13.Biaya Operasi;14.Waktu Input) = ");
			scanf("%d",&pilih_edit); 
			switch (pilih_edit){
			case 1:
				printf("\nkode : ");
				scanf(" %[^\n]%*c",data[no].dp.kode);
				break;
			case 2:
				printf("\nNama : ");
				scanf(" %[^\n]%*c",data[no].dp.nama);	
				break;
			case 3:
				printf("\npekerjaan : ");
				scanf(" %[^\n]%*c",data[no].dp.pekerjaan);	
				break;
			case 4:
				printf("\nNo HP : ");
				scanf(" %[^\n]%*c",data[no].dp.nohp);
				break;
			case 5:
				printf("\nUmur : ");
				scanf(" %[^\n]%*c",data[no].dp.umur);	
				break;
			case 6:
				printf("\nPenanggung Jawab : ");
				scanf(" %[^\n]%*c",data[no].dp.pj);
				break;
			case 7:
				printf("\nDiagnosa : ");
				scanf(" %[^\n]%*c",data[no].dp.diagnosa);	
				break;
			case 8:
				printf("\nAnamnesis :");
				scanf(" %[^\n]%*c",data[no].anamnesis);	
				break;
			case 9:
				printf("\nProsedur Operasi :");
				scanf(" %[^\n]%*c",data[no].proseduroperasi);
				break;
			case 10:
				printf("\nPost Operasi :");
				scanf(" %[^\n]%*c",data[no].postoperasi);
				break;
			case 11:
				printf("\nMedical Check Up :");
				scanf(" %[^\n]%*c",data[no].medicalcheckup);
				break;
			case 12:
				printf("Harga Obat :");
				scanf("%i", &data[no].bea.obat);
				break;
			case 13:
				printf("Biaya Operasi :");
				scanf("%i", &data[no].bea.operasi);
				break;
			case 14:
				printf("\nWaktu Input :");
				scanf("%i %i %i", &data[no].wkt.tanggal, &data[no].wkt.bulan, &data[no].wkt.tahun);
				break;
			default:
				printf("\npilihan salah");
				break;
			}
			printf("\nData berhasil diedit !");
			getch();
			system("cls");
			goto awal;
		}
	}else if(pilih==4){
		int no;
		tampil();
		printf("\nMasukkan nomor data yang akan dihapus : ");
		inputhapus:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data Pasien nomor ke %i, mohon masukkan kembali : ", no);
			goto inputhapus;
		}else{
			for(no;no<size;no++){
				strcpy(data[no].dp.kode,data[no+1].dp.kode);
				strcpy(data[no].dp.nama,data[no+1].dp.nama);
				strcpy(data[no].dp.pekerjaan,data[no+1].dp.pekerjaan);
				strcpy(data[no].dp.nohp,data[no+1].dp.nohp);
				strcpy(data[no].dp.umur,data[no+1].dp.umur);
				strcpy(data[no].dp.pj,data[no+1].dp.pj);
				strcpy(data[no].dp.diagnosa,data[no+1].dp.diagnosa);
				strcpy(data[no].anamnesis,data[no+1].anamnesis);
				strcpy(data[no].proseduroperasi,data[no+1].proseduroperasi);
				strcpy(data[no].postoperasi,data[no+1].postoperasi);
				strcpy(data[no].medicalcheckup,data[no+1].medicalcheckup);
				data[no].bea.obat = data[no+1].bea.obat;
				data[no].bea.operasi = data[no+1].bea.operasi;
				data[no].bea.total = data[no+1].bea.total;
				data[no].wkt.tanggal = data[no+1].wkt.tanggal;
				data[no].wkt.bulan = data[no+1].wkt.bulan;
				data[no].wkt.tahun = data[no+1].wkt.tahun;
			}
			printf("data berhasil dihapus");
			getch();
			system("cls");
			goto awal;
		}
	}else if(pilih==5){
		int pilih_sort;
		printf("Sorting Berdasarkan:\n1. Tanggal\n2. Nama\nPilih : ");
		scanf("%i", &pilih_sort);
		switch (pilih_sort)
		{
		case 1:
			sorting_tanggal();
			break;
		case 2:
			sorting_nama();
		default:
			break;
		}
		printf("data berhasil diurutkan");
		getch();
		system("cls");
		goto awal;
	}else if (pilih==6){
		int pilih_search;
		printf("Cari Berdasarkan:\n1. Tanggal\n2. Nama\nPilih urutan: ");
		scanf("%i", &pilih_search);
		switch (pilih_search)
		{
		case 1:
			searchByTanggal();
			break;
		case 2:
			searchByNama();
			break;
		default:
			break;
		}
		getch();
		system("cls");
		goto awal;
	}else if (pilih==7){
		printf("\nTerima Kasih!\n");
		endscreen();
	}else{
		printf("Inputan anda salah.");
		getch();
		system("cls");
		goto awal;
	}
	return 0;
}
