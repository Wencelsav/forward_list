struct list
{
  int field; // поле данных
  struct list *ptr; // указатель на следующий элемент
}
struct list * init(int a) // а- значение первого узла
{
  struct list *lst;
  // выделение памяти под корень списка
  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->ptr = NULL; // это последний узел списка
  return(lst);
}
struct list * deletelem(list *lst, list *root)
{
  struct list *temp;
  temp = root;
  while (temp->ptr != lst) // просматриваем список начиная с корня
  { // пока не найдем узел, предшествующий lst
    temp = temp->ptr;
  }
  temp->ptr = lst->ptr; // переставляем указатель
  free(lst); // освобождаем память удаляемого узла
  return(temp);
}
struct list * deletehead(list *root)
{
  struct list *temp;
  temp = root->ptr;
  free(root); // освобождение памяти текущего корня
  return(temp); // новый корень списка
}
void listprint(list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d ", p->field); // вывод значения элемента p
    p = p->ptr; // переход к следующему узлу
  } while (p != NULL);
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
struct list * swap(struct list *lst1, struct list *lst2, struct list *head)
{
  // Возвращает новый корень списка
  struct list *prev1, *prev2, *next1, *next2;
  prev1 = head;
  prev2 = head;
  if (prev1 == lst1)
    prev1 = NULL;
  else
    while (prev1->ptr != lst1) // поиск узла предшествующего lst1
      prev1 = prev1->ptr;
  if (prev2 == lst2)
    prev2 = NULL;
  else
    while (prev2->ptr != lst2) // поиск узла предшествующего lst2
      prev2 = prev2->ptr;
  next1 = lst1->ptr;  // узел следующий за lst1
  next2 = lst2->ptr;  // узел следующий за lst2
  if (lst2 == next1)
  {                       // обмениваются соседние узлы
    lst2->ptr = lst1;
    lst1->ptr = next2;
    if (lst1 != head)
      prev1->ptr = lst2;
  }
  else
    if (lst1 == next2)
    {
      // обмениваются соседние узлы
      lst1->ptr = lst2;
      lst2->ptr = next1;
      if (lst2 != head)
        prev2->ptr = lst2;
    }
    else
    {
      // обмениваются отстоящие узлы
      if (lst1 != head)
        prev1->ptr = lst2;
      lst2->ptr = next1;
      if (lst2 != head)
        prev2->ptr = lst1;
      lst1->ptr = next2;
    }
    if (lst1 == head)
      return(lst2);
    if (lst2 == head)
      return(lst1);
    return(head);
}
