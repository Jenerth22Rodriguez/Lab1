//volatile modifier for variables that chage due to hardware interrupts, RTC, etc...
volatile int var;
//Function with Pointers
void swap(int *x, int *y)
{
int temp;
temp = *x;
*x = *y;
*y = temp;
}
//A stack frame (fp) is used here for the subroutine(function) call.
//Also, the stack is used when switching between OS and main() too.
int main()
{
//local variables
int a, b;
a = 10;
b = 20;
swap(&a, &b);
return 0;
}
