#define MAX 50

typedef int ElementType;
typedef ElementType StackType[MAX];

extern int top;

extern void initialize(StackType stack);
extern int is_empty(StackType stack);
extern int is_full(StackType stack);
extern void push(ElementType e, StackType stack);
extern ElementType pop(StackType stack);
extern ElementType peek(StackType stack);