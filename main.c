#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

void jawabsaja (); //pilihan selesai jawab
void nilai(int n,int n2); //nilai akhir permainan
void pilihan (int x,int y,int c);

int main(int pernyataan, char *argument[]){
    time_t mulaisaja, end;
    int opsie,detiks,nambah=0,i=0,hitungan=0; // i untuk for loop , hitungan untuk meresult jawaban benar
    char inputnama[50],inputpass[50],c,d,f,pilmu; //pilmu= pilihan utama
    int soal[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //jumlah soal
    int pinalty,tambahanwaktu; //opsi bantuan pinalty untuk menghilangkan sebagian opsi, tambahan waktu untuk menambah wktu pengerjaan.

    if(pernyataan>2){//jika user menginput pernyataan lebih dari 2
        printf("Input yang anda masukkan salah!\n");
        return EXIT_FAILURE;
    }
    else if (pernyataan ==1){//jika user memasukkan satu argument
        system("cls"); //fungsi cls ini untuk menghapus riwayat program saat sedang berjalan
        printf("-----------------------------------------------------\n");
        printf("\t  SELAMAT DATANG WAHAI PEJUANG!\n");
        printf("-----------------------------------------------------\n");

        mainmenu:
            system ("color 07"); //ini input untuk memberi warna pada tulisan, jelas warnanya liat guguel aja. guna windows.h
            printf("1. Sign-in\n2. Log-in\n3. Kredit\n4. Keluar\n\n");//model cla
            printf("Masukkan pilihan anda: ");
            scanf("%i",&opsie);

            if(opsie == 2){//program untuk menampilkan cara login
                system("cls");
                printf("-----------------------------------------------------\n");
                printf("Apa kabar Lord! sign-in sudah??\nOkee... Mari memasuki arena!\n\nDengan cara input:");
                system("color 01");
                printf("./namaprogram namauser@code\nContoh : ./run kera@sakti\n||./run bisa diganti sesuai dengan kode masing-massing (tepat setelah : gcc namafile.c -o run)||\n");
                printf("-----------------------------------------------------\n");
                printf("\n  w-w Silakan menduduki kursi panas anda. w-w\n");
                printf("\n-----------------------------------------------------\n");
                return EXIT_FAILURE;
            }else if(opsie == 4){//program keluar
                system("cls");
                printf("\n-----------------------------------------------------\n\n");
                printf("\t TERIMAKASIH SUDAH BERKUNJUNG!!\n");
                printf("\n-----------------------------------------------------\n");
                return EXIT_FAILURE;
            }else if(opsie==3){
                system("cls");
                printf("\n\t\tProgram ini dikembangkan oleh :\n\n"
                  "1. Ainal Fajri M.\t|\t2008107010053\n" //tampilan kredit
                  "2. M. Khawaril Putra\t|\t2008107010038\n"
                  "3. Naufal Angkasah\t|\t2008107010018\n");
                printf("\n--------------------------------------------------\n\n\n");
                getch();
                goto mainmenu;
            }else if(opsie==1){//program untuk sign-in
                do{
                    //system("cls");
                    if(c == ' ') {
                        printf("Username yang anda masukkan salah!\n");
                        printf("|Username tidak terdapat spasi|\n");
                    }
                    printf("Masukkan username anda : \n");
                    printf("|Contoh => Mantra|\n->");
                    getchar();
                    scanf("%[^\n]s",inputnama);
                    do{
                        c=inputnama[i++];
                        if (isalnum(c) == 0) { //isalnum untuk mengetahui apakah karakter termasuk alfanumerik, menggunakan ctype.h
                            break;
                        }
                        }while(isalnum(c) != 0);
                }while(c == ' ');
                do{
                    if(c == ' ') {
                        printf("Password yang anda masukkan salah!\n");
                        printf("|password tidak terdapat spasi|\n");
                    }
                    system("cls");
                    printf("Masukkan Password : \n");
                    printf("->");
                    getchar();
                    scanf("%[^\n]s",inputpass);
                        while(isalnum(d) != 0){
                            d =inputpass[i++];
                            if (isalnum(d) == 0) {
                                break;
                                }
                            printf("%c..",d);
                        }
                }while(d == ' ');

                strcat(inputnama,"@");
                strcat(inputnama,inputpass);
                FILE* fip;

                char username[50];
                strcpy(username,inputnama);
                strcat(inputnama,".bin");

                getchar();
                if((fip=fopen(inputnama,"r"))!=NULL){//kalau username dan password sudah ada sebelumnya
                    system("cls");
                    system ("color 0c") ;
                    printf("\nMaaf, akun ini telah ada\nMohon gunakan username dan password yang berbeda\n");
                    printf("Klik 'enter' untuk kembali ke menu utama\n");
                    getch();
                    //system("cls");
                    goto mainmenu;
                }
                //program untuk menulis ke text binary
                FILE* finp = fopen(inputnama,"wb");
                fwrite(username, sizeof(char), sizeof(username)/sizeof(char), finp);

                fclose(finp);
                printf("\nLogin anda berhasil!");
                printf("\nGunakan akun %s untuk login game",username); //gak pake & karena pointer
                getchar();
                //system("cls");
                goto mainmenu;
            }
    }else if(pernyataan == 2){
        //program membaca file text binary
        strcpy(inputnama, argument[1]);
        char* user[3];
        user[0] = strtok(inputnama, "@");
        int kontrol=0;
        while(user[kontrol++] != NULL)
        {
            user[kontrol] = strtok(NULL, "@");
        }

        FILE *fpr; //referensi gugel di beberapa forum coding
        char inp[100];
        strcpy(inp, argument[1]);
        strcat(inp,".bin");
        //program ketika user belum mendaftar
        if((fpr = fopen(inp, "rb")) == NULL)
        {
            printf("\nMaaf, Anda belum mendaftar\nSilahkan daftar terlebih dahulu..\n");
            return EXIT_FAILURE;
        }
        //program untuk membaca isi  textbinary
        char akun[100];
        fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fpr);
        fclose(fpr);

        char *string[3];
        char username[50], password[50];
        //program untuk login
        string[0] = strtok(akun, "@");
        kontrol=0;
        while(string[kontrol++] != NULL)
        {
            string[kontrol] = strtok(NULL, "@");
        }
        strcpy(username, string[0]);
        strcpy(password, string[1]);

        if( (strcmp(user[0], username) == 0) && (strcmp(user[1], password) == 0) )
        {
            system("cls");
            system ("color 07") ;
            printf("\n-----------------------------------------------------\n");
            printf("\n   Selamat telah menjadi bagian dari game ini!\n    Tetap tenang dan waspada\n");
            getchar();
        }else
        {
            system ("color 0c") ;
            printf("\n-----------------------------------------------------\n");
            printf("\n    Gunakan otak cerdas! Jangan cuma disimpan!");
            printf("\nMaaf, akun anda tidak terdaftar\nSilahkan daftar dulu  menggunakan command ./namaprogram (Tepat setelah kode '-o')\n") ;
            return EXIT_FAILURE;
        }

        system("cls");
        system ("color 08") ;

        printf("\nWelcome %s!\n",username);
        getchar();
        //mulai permainan
        menuutama:
            system ("color 0f");
            system("cls");
            printf("\t\t\t\t\t+====================================================================+\t\t\t\t\t\n");
            printf("\t\t\t\t\t|                              WHO WANTS                             |\t\t\t\t\t\n");
            printf("\t\t\t\t\t|                          TO BE MILLIONAIRE                         |\t\t\t\t\t\n");
            printf("\t\t\t\t\t+====================================================================+\t\t\t\t\t\n");
            printf("\n");
            printf("\n\t\t\t\t\t > Tekan M untuk memulai permainan");
            printf("\n\t\t\t\t\t > Tekan R peraturan");
            printf("\n\t\t\t\t\t > Tekan Q untuk keluar");
            printf("\n\t\t\t\t-----------------------------------------------------------------------------------------\n");
            pilmu = toupper(getch());
            if (pilmu=='R'){
                  printf("\n\tketentuan Memainkan game\n" //Syarat permainan.
                        "\n1. Anda hanya memiliki 1 nyawa.\n2. Anda punya kesempatan untuk memilih lanjut atau keluar dari game."
                        "\n3. Waktu anda hanya 15 detik dalam 1 soal.\n4. Jika waktu habis sebelum anda menjawab, anda tereliminasi secara otomatis."
                        "\n5. Waktu tidak ditampilkan, maka gunakan sebaik mungkin."
                        "\n6. Jika anda kalah, semua uang yang anda dapatkan akan hangus."
                        "\n6. Terdapat optional tambahan seperti 50:50 dan tambahan waktu 5 detik, gunakan dengan bijak.");
                    printf("\n\nTekan enter untuk memulai permainan");
                    getch();
                    goto menuutama;
            }else if (pilmu == 'Q')                                 //pilihan cabut dari program
                exit(1);
            else if (pilmu == 'M') {
                hitungan=0,pinalty = 1,tambahanwaktu = 1;}
                goto mulaisaja;
                
                    system("cls");
                    mulaisaja:
                        for (i = 0; i < 15; i++) { //for loop untuk ubah soal otomatis
                            system("cls"); //membuat tampilan hanya soal sedang berlangsung yang nampak, sisanya akan tertimpa
                            switch (soal[i]) { //soal 1 - 10
                                case 1:
                                    mulaisaja = time (NULL);//program menjalankan waktu
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp50.000\n");
                                     printf("\nSoal nomor 1!\nApakah yang dimaksud dengan monera?\n");
                                     printf("a. Hewan melata dengan tubuh mungil\nb. Tapal kuda yang terbuat dari besi\nc. Sedimen runcing yang menjulang ke atas di kedalaman gua\nd. Hewan bersel satu yang dapat dilihat dengan mikroskop\n");
                                    pilihan(pinalty,tambahanwaktu,nambah);//fungsi pilihan tambhan
                                    qol:
                                        printf("\nPilihan anda => ");
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;

                                        if (detiks > 15+nambah){//program ketika user lambat menjawab
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;
                                        }
                                        if (tolower(f) == 'd') {
                                        jawabsaja();
                                        hitungan=hitungan+50000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nd. Hewan bersel satu yang dapat dilihat dengan mikroskop");
                                            }else{
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {  //program pilihan tambahan
                                            if (pinalty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Hewan melata dengan tubuh mungil\nd. Hewan bersel satu yang dapat dilihat dengan mikroskop");
                                                pinalty = 0;
                                                goto qol;
                                            }else {
                                                goto qol;
                                                }
                                        }
                                        else if(tolower(f)=='f'){//program pilihan tambahan
                                            if (tambahanwaktu== 1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto qol;
                                            }else{
                                                goto qol;
                                                }
                                        }
                                        else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nd. Hewan bersel satu yang dapat dilihat dengan mikroskop");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 2:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp500.000\n");
                                    printf("2. Nama lain dari \"Basemen\" adalah? \n");
                                    printf("a. Pavilium\tc. Korlet\n");
                                    printf("b. Rubanah\td. Plafon\n");
                                    pilihan(pinalty,tambahanwaktu,nambah);

                                    wol:
                                        printf("\nPilihan anda => ");
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;
                                        }
                                        if (tolower(f) == 'b') {
                                            jawabsaja();
                                            hitungan+=500000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nb. Rubanah");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if (pinalty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Pavilium\tb. Rubanah");
                                                pinalty = 0;
                                                goto wol;
                                            } else{
                                                goto wol;
                                                }
                                            }
                                        else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto wol;
                                            }else{
                                                goto wol;
                                                }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nb. Rubanah");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 3:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp1.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("3. A bat and a ball cost $1.10 in total. The bat costs a dollar more than the ball\nHow much does the ball costs?\n");
                                    printf("a. $0.1\tc. $0.5\n");
                                    printf("b. $0.2\td. $90\n");

                                    pilihan(pinalty,tambahanwaktu,nambah);

                                    eol:
                                        printf("\nPilihan anda => ");

                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'c') {
                                            jawabsaja();
                                            hitungan+=1000000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nc. $0.5");
                                            } else {
                                                break;
                                            }
                                        }else if (tolower(f) == 'e') {
                                            if (pinalty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. $0.1\tc. $0.5");
                                                pinalty = 0;
                                                goto eol;
                                            } else{ goto eol;}
                                        }else if(tolower(f)=='f') {
                                            if (tambahanwaktu == 1){
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto eol;
                                            }else {
                                                goto eol;
                                                }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nc. $0.5");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 4:
                                    system ("color 07") ;
                                    system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp.1.500.000\n\n");//klo bisa jangan disingkat:)
                                    printf("4. Kasur, jika diartikan ke dalam bahasa Inggris adalah?\n");
                                    printf("a. Bed\tc. Bat\n");
                                    printf("b. Bath\td. Bad\n");

                                    pilihan(pinalty,tambahanwaktu,nambah);

                                    rol:
                                        printf("\nPilihan anda => ");

                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            //system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'a') {
                                            jawabsaja();
                                            hitungan+=1500000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \na. Bed");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if(pinalty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Bed\n\td. Bad ");
                                                pinalty = 0;
                                                goto rol;
                                            } else{goto rol;}
                                        }else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto rol;
                                            } else{
                                                goto rol;
                                                }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nd. HewanCapture");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 5:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp2.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("5. Manakah rumus kimia dari \"Natrium Klorida\"?\n");
                                    printf("a. C2H3NaO2\tc. Na2SO4\n");
                                    printf("b. C7H5NaO2\td. NaCl\n");
                                    pilihan(pinalty,tambahanwaktu,nambah);

                                    tol:
                                        printf("\nPilihan anda => ");
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;//sampai sini
                                            }
                                        if (tolower(f) == 'd') {
                                            jawabsaja();
                                            hitungan+=2000000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nd. NaCl");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if (pinalty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nb. C7H5NaO2\td. NaCl\n");
                                                pinalty = 0;
                                                goto tol;
                                            } else{
                                                goto tol;
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto tol;
                                            } else{
                                                goto tol;
                                            }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nd. NaCl");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 6:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp5.000.000\n\n");
                                    printf("6. Dalam penggunaan mobil matic, manakah fungsi gigi yang tepat untuk tanjakan yang tidak terlalu curam? \n"
                                        "a. D-3\tc. L\n"
                                        "b. N\td. 2 \n");

                                    pilihan(pinalty,tambahanwaktu,nambah);
                                    yol:
                                        printf("\nPilihan anda => ");
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'd') {
                                            jawabsaja();
                                            hitungan+=5000000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nd. 2");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e'){
                                            if (pinalty==1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\nb. N\td. 2\n");
                                                pinalty = 0;
                                                goto yol;
                                            } else{goto yol;}
                                            }
                                        else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto yol;
                                            } else{
                                                goto yol;
                                            }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nd. 2");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 7:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp10.000.000\n\n");
                                    printf("7. Hewan apakah yang mempunyai nama latin \"Cimicidae\"\n"
                                        "a. Anjing\tc. monyet\n"
                                        "b. Kutu Busuk\td. Kampret\n");
                                    pilihan(pinalty,tambahanwaktu,nambah);
                                    uol:
                                        printf("\nPilihan anda => ");

                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'b') {
                                            jawabsaja();
                                            hitungan+=10000000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nb. Kutu Busuk");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (pinalty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\tc. Monyet\nb. Kutu Busuk");
                                                pinalty = 0;
                                                goto uol;
                                            } else {
                                                goto uol;
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto uol;
                                            } else {
                                                goto uol;
                                                }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nb. Kutu Busuk");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 8:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp20.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("8. Kota apakah yang dijuluki dengan 'Kota Kembang'?\n"
                                        "a. Palangkaraya\tc. Bandung\n"
                                        "b. Cirebon\td. Jakarta\n\n");
                                    pilihan(pinalty,tambahanwaktu,nambah);

                                    iol:
                                        printf("\nPilihan anda => ");
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                            printf ("Maaf, anda telat menjawab.\n");
                                            getchar();
                                            goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'c') {
                                            jawabsaja();
                                            hitungan+=20000000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nc. Bandung");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (pinalty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\n\tc. Bandung\n\td. Jakarta");
                                                pinalty = 0;
                                                goto iol;
                                            } else {
                                                goto iol;
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto iol;
                                            } else{
                                                goto iol;
                                                }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nc. Bandung");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 9:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp.25.000.000\n\n");//klo bisa jangan disingkat:)
                                    printf("9. Ibokuta negara Slovakia adalah?\n"
                                        "a. Lusaka\tc. Caracas\n"
                                        "b. Brastislava\td. Doha\n\n");

                                    pilihan(pinalty,tambahanwaktu,nambah);

                                    ool:
                                        printf("\nPilihan anda => ");
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                        printf ("Maaf, anda telat menjawab.\n");
                                        getchar();
                                        goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'b') {
                                            jawabsaja();
                                            hitungan+=25000000;
                                            if (toupper(getch()) == 'N') {
                                                goto nilaiuser;
                                                printf("\n\nBenar! Jawaban adalah: \nb. Bratislava");
                                            } else {
                                                break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (pinalty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Lusaca\nb. Brastislava");
                                                pinalty = 0;
                                                goto ool;
                                            } else {
                                                goto ool;
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto ool;
                                            } else {
                                                 goto ool;
                                                 }
                                        } else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \nb. Brastislava");
                                            getch();
                                            goto nilaiuser2;
                                        }
                                case 10:
                                    system ("color 07") ;
                                    //system("cls");
                                    mulaisaja = time (NULL);
                                    printf("\nJika anda benar, maka anda mendapatkan uang sebesar Rp.50.000.000\n\n");
                                    printf("10. Penemu bilangan bulat adalah?\n"
                                        "a. Leonardo Da Pisa\tc. Leonardo Da Vinci\n"
                                        "b. Cristoper Colombus\td. Leonardo De Caprio\n");
                                    printf("\nPilihan anda => ");
                                    pilihan(pinalty,tambahanwaktu,nambah);
                                    pol:
                                        f=getch();
                                        end = time (NULL);
                                        detiks = end - mulaisaja;
                                        if (detiks > 15+nambah){
                                            system("cls");
                                        printf ("Maaf, anda telat menjawab.\n");
                                        getchar();
                                        goto nilaiuser2;//sampai sini
                                        }
                                        if (tolower(f) == 'a') {
                                            jawabsaja();
                                            hitungan+=50000000;
                                            if(toupper(getch())=='N'){
                                              goto nilaiuser;
                                              printf("\n\nBenar! Jawaban adalah: \na. Leonardo Da Pisa");
                                            } else{
                                              break;
                                            }
                                        }else if(tolower(f)=='e') {
                                            if (pinalty == 1) {
                                                printf("\n50:50 telah dipakai\n");
                                                printf("\na. Leonardo Da Pisa\tc. Leonardo Da Vinci");
                                                pinalty = 0;
                                                goto pol;
                                            } else {
                                                goto pol;
                                                }
                                        }else if(tolower(f)=='f'){
                                            if (tambahanwaktu==1) {
                                                printf("\nTambahan 5 detik telah dipakai\n");
                                                nambah = 5;
                                                tambahanwaktu = 0;
                                                goto pol;
                                            } else{
                                                goto pol;
                                                }
                                        }else {
                                            system ("color 0c") ;
                                            printf("\n\nSalah! Jawabannya adalah : \na. Leonardo Da Pisa");
                                            getch();
                                            goto nilaiuser2;
                                        }
                            }
                        }
                }else{
                    goto menuutama;
                nilaiuser:             // Hitungan semua nilai pemain
                    nilai(hitungan,1);
                    goto menuutama;
                nilaiuser2:
                    nilai(hitungan,2);
                    goto menuutama;
            }
        return 0;
}
void pilihan (int x,int y,int z) {
    z = 0;
    printf("\nOpsi pembantu :\n");
    if (x > 0) {
        printf("\te. 50:50\t");
    }
    if (y > 0) {
        printf("f. Tambahan 5 detik\n");
    }
    if (x == 0) {
        if (y == 0) {
            printf("(Anda sudah menggunakan semua opsi)\n");
            }
    }
}
void jawabsaja () {
    system ("color 0a") ;
    printf("\n\nJawaban Benar!!!\n");
    printf("\nApakah anda ingin melanjukan?");
    printf("\n=> Tekan apapun untuk melanjutkan"
           "\n=> Tekan 'N' jika anda merasa sudah cukup!");
}
void nilai(int n, int n2){
   int nilaiuser;
    if (n2==1){
        system ("color 01") ;
        system("cls");
        nilaiuser=n;
        printf("\n\n\t\t$$$$$$$$$$$$$=== SELAMAT ===$$$$$$$$$$$$$");
        printf("\n\n\t Anda menang!!! Anda berhak mendapatkan uang virtual senilai Rp%d",nilaiuser); //nilai untuk pemain yang menang
        printf(" \n\n\tTekan apa saja untuk kembali ke halaman utama");
        printf("\n-----------------------------------------------------------------------------------------\n");
        getch();
    } else if (n2==2){
        system("cls");
        system ("color 0c") ;
        printf("\n\n\t\t$$$$$$$$$$$$$=== GAME BERAKHIR ===$$$$$$$$$$$$$");
        printf("\n\n\t Anda Ceroboh! Membuat Anda tidak mendapatkan sepeser pun!!\n\t Dah boleh pulang, silakan!"); //untuk user game over
        printf(" \n\n\tTekan apa saja untuk kembali ke halaman utama");
        getch();
        printf("\n-----------------------------------------------------------------------------------------\n");
    }
}
