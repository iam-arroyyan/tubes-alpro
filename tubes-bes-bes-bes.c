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

struct rekam_medis{
	struct data_pasien dp;
	char anamnesis[500];
	char proseduroperasi[500];
	char postoperasi[500];
	char medicalcheckup[500];
	struct waktu wkt;
};
typedef struct rekam_medis remed;


remed data[50];

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
	printf("Waktu Input : ");
	scanf("%i %i %i", &data[size].wkt.tanggal, &data[size].wkt.bulan, &data[size].wkt.tahun);
	size++;
}

void tampil(){
	int i;
	if(size>0){
		for(i=1;i<size;i++){
			x=strlen(data[i].dp.kode); //panjang dari string 
			if(x>=1){
			printf("--REKAM MEDIS--");
			printf("\nIdentitas Pasien ke - [%d]\n",i);
			printf("Kode \t\t\t: %s\n",data[i].dp.kode);	
			printf("Nama \t\t\t: %s\n",data[i].dp.nama);
			printf("Pekerjaan \t\t: %s\n",data[i].dp.pekerjaan);
			printf("No HP \t\t\t: %s\n",data[i].dp.nohp);
			printf("Umur \t\t\t: %s\n",data[i].dp.umur);
			printf("Penanggung Jawab \t: %s\n",data[i].dp.pj);
			printf("Diagnosa \t\t: %s\n",data[i].dp.diagnosa);
			printf("--ANAMNESIS--\n%s\n",data[i].anamnesis);	
			printf("--PROSEDUR OPERASI--\n%s\n",data[i].proseduroperasi);	
			printf("--POST OPERASI--\n%s\n",data[i].postoperasi);	
			printf("--MEDICAL CHECK-UP--\n%s\n",data[i].medicalcheckup);	
			printf("Waktu Input \t\t: %i/%i/%i\n\n", data[i].wkt.tanggal, data[i].wkt.bulan, data[i].wkt.tahun);
			}
		}
	}
}
int main() {
	size = sizeof(remed)/sizeof(data[0]);
	int i=1;
	int pilih=0,pilih_edit;
	char kode[12],nama[50],pekerjaan[50],nohp[14],umur[4],pj[50],diagnosa[400];
	char anamnesis[500],proseduroperasi[500],postoperasi[500],medicalcheckup[500];
	awal:
	printf("====== Data Pasien ======\n");
	printf("Menu :\n1. Tampil Data\n2. Tambah Data\n3. Update Data\n4. Hapus Data\n5. Keluar\nPilih menu : ");
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
			printf("Tidak ada data Pasien nomor ke %d, mohon masukkan nomor kembali : ");
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
			printf("Waktu Input \t\t: %i/%i/%i\n\n", data[i].wkt.tanggal, data[i].wkt.bulan, data[i].wkt.tahun);
			printf("\nPilih data yang ingin diedit sesuai nomor (1.Kode;2.Nama;3.Pekerjaan;4.No Hp;5.Umur;6.Penanggung Jawab;7.Diagnosa;8.Anamnesis;9.Prosedur Operasi;10.Post Operasi;11.Medical Check Up;12.Waktu Input) = ");
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
			printf("Tidak ada data Pasien nomor ke %d, mohon masukkan kembali : ");
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
		printf("\nTerima Kasih!");
	}else{
		printf("Inputan anda salah.");
	}
	return 0;
}