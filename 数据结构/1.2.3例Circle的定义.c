// #include<stdio.h>
// #include<stdlib.h>

// #define PI 3.14
// typedef struct 
// {
// 	double r, x, y;
	
// }Circle;
// void InitCircle__010203(Circle* c, double rencentr, double rencentx, double rencenty)
// {

// 	c->r = rencentr;
// 	c->x = rencentx;
// 	c->y = rencenty;
// }
// double Area_Of_Circle__010203(const Circle *c)
// {
// 	return c->r * c->r * PI;
// }
// double Circumference_Of_Circle__010203(const Circle *c)
// {
// 	return 2 * PI * c->r;
// }
// void Destroy_Circle__010203(Circle** c_ptr)
// {
// 	if (c_ptr != NULL && *c_ptr != NULL)
// 	{
// 		free(*c_ptr);
// 		*c_ptr = NULL;
// 	}
// }
// int main__010203()
// {
// 	Circle *myCircle=(Circle*)malloc(sizeof(Circle));
// 	InitCircle__010203(myCircle, 2, 0, 0);

// 	//打印半径与面积
// 	printf("Circle Radius: %.2f\n", myCircle->r);
// 	printf("Area:%.2f\n", Area_Of_Circle__010203(myCircle));
// 	//打印周长
// 	printf("Circumference:%.2f\n", Circumference_Of_Circle__010203(myCircle));

// 	//销毁圆
// 	Destroy_Circle__010203(&myCircle);

// 	//成功销毁后再次访问会报错
// 	//printf__010203("%f",myCircle->r);
	
// 	return 0;
// }
 //\b(?!if|for|switch|return)(\w+)\s*\(