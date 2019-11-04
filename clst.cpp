#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
 

struct Point{
    int x, y;
};

int compareX(const void* a, const void* b){
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b){
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 

float dist(Point p1, Point p2){
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 

float simple_distance(Point P[], int n){
    float min = FLT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
 

float min(float x, float y){
    return (x < y)? x : y;
}
 
 

float close_strip(Point strip[], int size, float d){
    float min = d;  
    qsort(strip, size, sizeof(Point), compareY);
 
   
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}
 

float closepoints(Point P[], int n){

    if (n <= 3)
        return simple_distance(P, n);
 
    int mid = n/2;
    Point midPoint = P[mid];
   
    float l = closepoints(P, mid);
    float r = closepoints(P + mid, n-mid);

    float d = min(l, r);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
        {
            strip[j] = P[i];
        j++;
        }
   
    return min(d, close_strip(strip, j, d) );
}
 

float closest(Point P[], int n){
    qsort(P, n, sizeof(int), compareX);
 
    return closepoints(P, n);
}
 

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
    return 0;
}