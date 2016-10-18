#include<bits/stdc++.h>
#define nl "\n" 
using namespace std;

void initial_permutation(int IP[],int plain_text[]){
	std::fstream file("IP.txt",std::ios_base::in);
	int IP_indeks[65],indeks;
	for(int i=1;i<65;i++){
		file>>IP_indeks[i];
	}
	for(int i=1;i<65;i++){
		indeks=IP_indeks[i];
		IP[i]=plain_text[indeks];
	}	
}

void display(int m[]){
	int tempo=9;
	for(int indeks=1;indeks<65;indeks++){			
		if(indeks==tempo){
			cout<<nl<<m[indeks]<<" ";
			tempo+=8;
		}else{
			cout<<m[indeks]<<" ";
		}
	}
}

void setLRprev(int Lprev[],int Rprev[], int IP[]){
	int temp=1;
	for(int i=1;i<33;i++){
		Lprev[i]=IP[i];
	}
	
	for(int j=33;j<65;j++){
		Rprev[temp]=IP[j];
		temp++;
	}	
}

void setLRnext(int Lprev[],int Rprev[],int Lnext[],int Rnext[]){
	for(int i=1;i<33;i++){
		Lnext[i]=Rprev[i];
	}

	for(int i=1;i<33;i++){
		Rprev[i]=Rnext[i];
		Lprev[i]=Lnext[i];
	}
}

void Permuted_Choice1(int PC1[],int key[]){
	std::fstream file("PC1.txt",std::ios_base::in);
	int PC1_indeks[57],indeks;
	for(int i=1;i<57;i++){
		file>>PC1_indeks[i];
	}
	for(int i=1;i<57;i++){
		indeks=PC1_indeks[i];
		PC1[i]=key[indeks];
	}
}

void Permuted_Choice2(int PC2[],int C[],int D[]){
	int key_shift[57];
	for(int i=1;i<29;i++){
		key_shift[i]=C[i];
	}
	int tem=29;
	for(int i=1;i<29;i++){
		key_shift[tem]=D[i];
		tem++;
	}
	
	std::fstream file("PC2.txt",std::ios_base::in);
	int PC2_indeks[49],indeks;
	for(int i=1;i<49;i++){
		file>>PC2_indeks[i];
	}	
	for(int i=1;i<49;i++){
		indeks=PC2_indeks[i];
		PC2[i]=key_shift[indeks];
	}
}

void setCDprev(int C[],int D[],int PC1[]){
	for(int i=1;i<29;i++){
		C[i]=PC1[i];
	}
	int tem=29;
	for(int i=1;i<29;i++){
		D[i]=PC1[tem];
		tem++;
	}	
}

void left_shift(int ronde,int C[],int D[]){
	int c1=C[1],d1=D[1];
	if(ronde==1 || ronde==2 || ronde==9 || ronde==16){
		for(int i=1;i<28;i++){
			C[i]=C[i+1];
			D[i]=D[i+1];
		}
		C[28]=c1;
		D[28]=d1;
	}else{
		for(int j=1;j<=2;j++){
			c1=C[1],d1=D[1];
			for(int i=1;i<28;i++){
				C[i]=C[i+1];
				D[i]=D[i+1];
			}
			C[28]=c1;
			D[28]=d1;
		}
	}
}

void Expansion(int Exp[],int Rprev[]){
	std::fstream file("Exp.txt",std::ios_base::in);
	int Exp_indeks[49],indeks;
	for(int i=1;i<49;i++){
		file>>Exp_indeks[i];
	}
	for(int i=1;i<49;i++){
		indeks=Exp_indeks[i];
		Exp[i]=Rprev[indeks];
	}	
}

void XOR(int m1[],int m2[],int m3[]){
	for(int i=1;i<49;i++){
		if(m1[i]!=m2[i]){
			m3[i]=1;
		}else{
			m3[i]=0;
		}
	}
}

int tempp=0; 							
void dec_bin(int D, int SboxOut[]){
				
	int dec=D, arr_biner[5];
	int sisa,dapet;
	for(int i=4;i>=1;i--){
		sisa=dec%2;
		arr_biner[i]=sisa;
		dec/=2;
	}
	for(int i=1;i<=4;i++){
		SboxOut[tempp+1]=arr_biner[i];
		tempp++;
	}
}

int getSboxtable(int biner[7]){		
	int rrow[3],rcol[5],rowdec=0,coldec=0,indeks;
	
	rrow[1] = biner[1];
	rrow[2] = biner[6];
	for(int i=1;i<=4;i++){
		rcol[i]=biner[i+1];
	}
	
	for(int i=1;i<3;i++){
		rowdec=rowdec+rrow[i]*pow(2,2-i);
	}
	
	for(int i=1;i<5;i++){					
		coldec=coldec+rcol[i]*pow(2,4-i);
	}
	indeks=rowdec*16+coldec;
	
	return indeks;
}

void sbox(int Sbox[],int SboxOUt[]){
	int s1[7],s2[7],s3[7],s4[7],s5[7],s6[7],s7[7],s8[7];
	int tem;
	for(int i=1;i<7;i++){
		s1[i]=Sbox[i];
	}	
	tem=7;
	for(int i=1;i<7;i++){
		s2[i]=Sbox[tem];
		tem++;
	}
	for(int i=1;i<7;i++){
		s3[i]=Sbox[tem];
		tem++;
	}
	for(int i=1;i<7;i++){
		s4[i]=Sbox[tem];
		tem++;
	}
	for(int i=1;i<7;i++){
		s5[i]=Sbox[tem];
		tem++;
	}
	for(int i=1;i<7;i++){
		s6[i]=Sbox[tem];
		tem++;
	}
	for(int i=1;i<7;i++){
		s7[i]=Sbox[tem];
		tem++;
	}
	for(int i=1;i<7;i++){
		s8[i]=Sbox[tem];
		tem++;
	}
	
	std::fstream file("S1.txt",std::ios_base::in);
	int dec1;int l1=getSboxtable(s1);
	for(int i=0;i<=l1;i++){
		file>>dec1;
	}dec_bin(dec1,SboxOUt);

	std::fstream file2("S2.txt",std::ios_base::in);
	int dec2;int l2=getSboxtable(s1);
	for(int i=0;i<=l2;i++){
		file2>>dec2;
	}dec_bin(dec2,SboxOUt);

	std::fstream file3("S3.txt",std::ios_base::in);
	int dec3;int l3=getSboxtable(s1);
	for(int i=0;i<=l3;i++){
		file3>>dec3;
	}dec_bin(dec3,SboxOUt);
	
	std::fstream file4("S4.txt",std::ios_base::in);
	int dec4;int l4=getSboxtable(s1);
	for(int i=0;i<=l4;i++){
		file4>>dec4;
	}dec_bin(dec4,SboxOUt);
	
	std::fstream file5("S5.txt",std::ios_base::in);
	int dec5;int l5=getSboxtable(s1);
	for(int i=0;i<=l5;i++){
		file5>>dec5;
	}dec_bin(dec5,SboxOUt);
	
	std::fstream file6("S6.txt",std::ios_base::in);
	int dec6;int l6=getSboxtable(s1);
	for(int i=0;i<=l6;i++){
		file6>>dec6;
	}dec_bin(dec6,SboxOUt);
	
	std::fstream file7("S7.txt",std::ios_base::in);
	int dec7;int l7=getSboxtable(s1);
	for(int i=0;i<=l7;i++){
		file7>>dec7;
	}dec_bin(dec7,SboxOUt);
	
	std::fstream file8("S8.txt",std::ios_base::in);
	int dec8;int l8=getSboxtable(s1);
	for(int i=0;i<=l8;i++){
		file8>>dec8;
	}dec_bin(dec8,SboxOUt);
}

void Permut(int Permutation[],int SboxOut[]){
	std::fstream file("permutation.txt",std::ios_base::in);
	int Perm_indeks[33],indeks;
	for(int i=1;i<33;i++){
		file>>Perm_indeks[i];
	}
	for(int i=1;i<33;i++){
		indeks=Perm_indeks[i];
		Permutation[i]=SboxOut[indeks];
	}
}

void inv_IP(int Cipher_text[],int Lnext[],int Rnext[]){
	int dummy[65],tem=1;
	for(int i=1;i<33;i++){
		dummy[tem]=Rnext[i];
		tem++;
	}
	for(int i=1;i<33;i++){
		dummy[tem]=Lnext[i];
		tem++;
	}
	std::fstream file("inv_IP.txt",std::ios_base::in);
	int invIP_indeks[65],indeks;
	for(int i=1;i<65;i++){
		file>>invIP_indeks[i];
	}
	for(int i=1;i<65;i++){
		indeks=invIP_indeks[i];
		Cipher_text[i]=dummy[indeks];
	}	
}
int tempor=1;
void gen_bit(int plain_text[],string plain){
	int arr_biner[8],dec;
	int sisa,dapet;
	for(int i=0;i<plain.size();i++){
		dec=(int)plain[i];
		for(int i=7;i>=0;i--){
			sisa=dec%2;
			arr_biner[i]=sisa;
			dec/=2;
		}
		for(int i=0;i<8;i++){
			plain_text[tempor]=arr_biner[i];
			tempor++;
		}
	}
}
/*-------------------decrypt function------------------*/

void useKey(int ronde,int C[],int D[],int saveC[17][29],int saveD[17][29]){
	for(int i=1;i<29;i++){
		C[i]=saveC[ronde][i];
		D[i]=saveD[ronde][i];
	}
}


void saveKey(int saveC[17][29],int saveD[17][29],int C[],int D[],int ronde){
	for(int i=1;i<29;i++){
		saveC[ronde][i]=C[i];
		saveD[ronde][i]=D[i];
	}
}



int main(){
	int plain_text[65],key[65],Cipher_text[65];
	int IP[65],PC1[57],PC2[49],Exp[49],Sbox[49],SboxOut[33],Permutation[33];
	int Lprev[33],Lnext[33],Rprev[33],Rnext[33],C[29],D[29];
	int saveC[17][29],saveD[17][29];
	
	int indeks;
	string plaintext;
	cin>>plaintext;
	srand(time(NULL));
	
	gen_bit(plain_text,plaintext);							//generate plaintext into bit
	
	for(indeks=1;indeks<65;indeks++){			//generate key
		key[indeks]=rand()%2;
	}
	
	cout<<"Plaintext"<<nl;
	display(plain_text);cout<<nl<<nl;
			
	/*----------Encrypt-----------*/		
	/*Start Round*/
	int round=1;
	initial_permutation(IP,plain_text);
	Permuted_Choice1(PC1,key);	
	setLRprev(Lprev,Rprev,IP);setCDprev(C,D,PC1);
		
			
	while(round<=16){
				
								left_shift(round,C,D); 
								saveKey(saveC,saveD,C,D,round);
		Expansion(Exp,Rprev);	Permuted_Choice2(PC2,C,D);
		
		XOR(Exp,PC2,Sbox);
	
		sbox(Sbox,SboxOut);	
		
		Permut(Permutation,SboxOut);
		
		XOR(Lprev,Permutation,Rnext);
		
		setLRnext(Lprev,Rprev,Lnext,Rnext);	
				
		round++;
	}
	inv_IP(Cipher_text,Lnext,Rnext);
	cout<<"Ciphertext"<<nl;
	display(Cipher_text);
	
	
	
	/*----------Decrypt-----------*/		
	/*round=16;
	
	initial_permutation(IP,Cipher_text);	
	setLRprev(Lprev,Rprev,IP);
	cout<<nl<<nl;
			
	while(round>0){
				
								useKey(round,C,D,saveC,saveD);
		Expansion(Exp,Rprev);	Permuted_Choice2(PC2,C,D);
		
		XOR(Exp,PC2,Sbox);
	
		sbox(Sbox,SboxOut);	
		
		Permut(Permutation,SboxOut);
		
		XOR(Lprev,Permutation,Rnext);
		
		setLRnext(Lprev,Rprev,Lnext,Rnext);
				
		round--;
	}
	inv_IP(Cipher_text,Lnext,Rnext);
	cout<<"Plaintext Decrypt"<<nl;
	display(Cipher_text);
	*/
		
}
