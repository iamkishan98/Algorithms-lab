#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Point {
  int x;
  int y;

};
float min(float a, float b){
    return (a < b)? a : b;
}


 
void merge(Point arr[],int l,int mid,int h){
  int m = mid-l+1;
  int n = h-mid;
  Point l1[m],l2[n];
  int i,j,k;
  for(i=0;i<m;i++){
    l1[i].x= arr[l+i].x;
    l1[i].y = arr[l+i].y;
  }
  for(i=0;i<n;i++){
    l2[i].x = arr[mid +i+1].x;
    l2[i].y = arr[mid+i+1].y;
  }

  i=0;
  k=l;
  j=0;

    while(i<m && j<n){
      if(l1[i].x  <  l2[j].x){
        arr[k].x = l1[i].x;
        arr[k].y = l1[i].y;
        i ++;
      }
      else{
        arr[k].x = l2[j].x;
        arr[k].y = l2[j].y;
        j ++;
      }

       k++;
    }

    while(i< m){
      arr[k].x = l1[i].x;
      arr[k].y = l1[i].y;
      i ++;
      k ++;
    }

    while(j < n){
      arr[k].x = l2[j].x;
      arr[k].y = l2[j].y;
      j ++;
      k ++;
    }


}
void mergesort(Point arr[] , int l,int h){
  if(l<h){
    int mid = l +(h-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,h);
    merge(arr,l,mid,h);
  }
}


float dist(Point p1,Point p2){
 return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}


float caldist(Point p[] ,int n){
  float min = FLT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (dist(p[i], p[j]) < min)
                min = dist(p[i], p[j]);
    return min;
}


int comy(const void* m, const void* n){
    Point *p1 = (Point *)m,   *p2 = (Point *)n;
    return (p1->y - p2->y);
}

 int comx(const void* a, const void* b){
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

float calarea(Point area[],int j ,float d){
  float min = d;  
    qsort(area, j, sizeof(Point), comy);
 
   
    for (int i = 0; i < j; ++i)
        for (int k = i+1; k <j  && (area[k].y - area[i].y) < min; ++k)
            if (dist(area[i],area[k]) < min)
                min = dist(area[i], area[k]);
 
    return min;
}

float closepair(Point p1[],int n,int low){
  
  if(n <= 3){
    return caldist(p1,n);
  }
  int mid = low +(n -low)/2;
  Point midpoint = p1[mid];
  float d1= closepair(p1, mid,low);
  float d2 = closepair(p1 + mid,n-mid,low);
  float d = min(d1,d2);
  int j = 0;
  Point area[n];
    for (int i = 0; i < n; i++){
        if (abs(p1[i].x - midpoint.x) < d)
        {
            area[j] = p1[i];
        j++;
        }
    }

return min(d, calarea(area,j,d));


  //return d;
}


float close(Point P[], int n ,int low ){
    qsort(P, n, sizeof(Point), comx);
 
    return closepair(P, n ,low );
}

int main(){
  Point p[] ={{123, 521}, {256, 963}, {457,125 }, {788, 456}};
  int n = sizeof(p)/sizeof(p[0]);
  mergesort(p,0,n-1);
  for(int i=0;i<n;i++){
    cout<<p[i].x<<" ,"<<p[i].y<<"\n";
  }
  Point pl[n/2+1], pr[n-((n/2)+1)];
  int j;
  for(j=0; j< n/2 ;j++){
    pl[j].x = p[j].x;
    pl[j].y = p[j].y;
  }
  int i;
  int k=0;
  for(i=j;i<n;i++){
    pr[k].x = p[i].x;
    pr[k].y = p[i].y;
    k ++;
  }
  
 int l=0;
 //int h=n-1;
  float dist =close(p,n-1,l);
  cout<<dist<<"\n";
  return 0;
}
