#include<stdio.h>

typedef struct{
	float x,y;
}point;

typedef struct{
	point topleft,bottomright;
}rect;

void display(rect);
float area(rect);
float perimeter(rect);
point centerPoint(rect);
int isSquare(rect);
int toInteger(char st[]);


int main(){
	int s,i;
	char arr[200][50];
	rect sam;
	point cp; 
	
	printf("Test number of cases:\n");
	scanf("%d",&s);
	printf("\n");
	for(i=0;i<s*4;i++){
		scanf("%s %s %s %s",&arr[i],&arr[i+1],&arr[i+2],&arr[i+3]);
		i+=3;
	}
	for(i=0;i<s*4;i++){
		printf("\n");
		sam.topleft.x = toInteger(arr[i]);
		sam.topleft.y = toInteger(arr[i+1]);
		sam.bottomright.x = toInteger(arr[i+2]);
		sam.bottomright.y = toInteger(arr[i+3]);
		cp = centerPoint(sam);
		display(sam);
		if(isSquare(sam)){printf("\nSQUARE");}else printf("\nRECTANGLE");
		printf("\nAREA: %g",area(sam));
		printf("\nPERIMETER: %g",perimeter(sam));
		printf("\nCENTER POINT: (%.2f,%.2f)",cp.x,cp.y);
		i+=3;
	}
	

	return 0;
}

void display(rect d){
	point 	p1 = d.topleft,
			p2 = d.bottomright;
	int x,y;
		
	for(y=0;y!=p2.y+1;y++){
		for(x=0;x!=p2.x+1;x++){
			if(x>=p1.x&&y>=p1.y){
				if(x==p1.x||y==p1.y||x==p2.x||y==p2.y){printf("# ");}else printf("  ");
			}
			else printf("  ");
		}
		printf("\n");
	}
}

float area(rect r){return ((r.bottomright.x-r.topleft.x)*(r.bottomright.y-r.topleft.y));}
float perimeter(rect r){return ((2*(r.bottomright.x-r.topleft.x))+(2*(r.bottomright.y-r.topleft.y)));}

point centerPoint(rect r){
	point cp;
	cp.x = (r.bottomright.x+r.topleft.x)/2.0;
	cp.y = (r.bottomright.y+r.topleft.y)/2.0;
	return cp;
}

int isSquare(rect r){if((r.bottomright.x-r.topleft.x)==(r.bottomright.y-r.topleft.y))return 1;return 0;}

int toInteger(char st[]){
	char a[]="0123456789";
	int i,j,r,z,w,t=1,s=0,q=0,neg=0;
	if(st[0]=='-')neg=1;
	while (st[q]!='\0')q++;
	for(i=0+neg;i<q;i++){
		for(j=0;j<(sizeof(a)/sizeof(*a));j++){
			w=0;
			if(st[i]=='.'){
				t=10;
				for(r=0;r<q-1-i;r++)t*=10; 
				if(neg)return (s/t)*-1;
				return s/t;
			}
			if(st[i]==a[j]){
				t=1;
				for(r=0;r<q-1-i;r++)t*=10;
				z=t*j;
				w=1;
				break;
			}
		}
		if(!w)return -1;
		s+=z;
	}
	if(neg)return s*-1;
	return s;
}

