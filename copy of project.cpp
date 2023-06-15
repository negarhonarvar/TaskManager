#include "clui.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct date
{
    int year;
    int month;
    int day;
};
struct task
{
    char* title;
    char* desc;
    int priority;
    date deadline;
};
task* new_task()
{
    task* user_task = new task;
    user_task->title = new char[100];
    user_task->desc = new char[400];

    change_color_rgb(190, 100, 100);
    printf("Please Enter The Task Title:");
    reset_color();
    change_color_rgb(190, 100, 100);
    scanf(" %[^\n]%*c",user_task->title);
    reset_color();
    change_color_rgb(220, 80, 80);
    printf("Please Enter The Task Description :");
    reset_color();
    change_color_rgb(220, 80, 80);
    scanf(" %[^\n]%*c", user_task->desc);
    reset_color();
    change_color_rgb(180, 65, 90);
    printf("Please Enter The Task Priority :");
    reset_color();
    change_color_rgb(180, 65, 90);
    scanf("%d", &user_task->priority);
    reset_color();
    change_color_rgb(150, 65, 90);
    printf("Please Enter The Task's Deadline : ");
    reset_color();
    change_color_rgb(150, 65, 90);
    scanf("%d/%d/%d",&user_task->deadline.year,&user_task->deadline.month,&user_task->deadline.day);
    reset_color();
    return user_task;
}
void bubble_sort(task** tasks,int n)
{

  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1-i;j++)
    {
        if(tasks[j+1]->priority < tasks[j]->priority)
         {
             task* temp;
             temp=tasks[j];
             tasks[j]=tasks[j+1];
             tasks[j+1]=temp;

         }
    }
  }
}
task** delete_task(task** user_task,int &number,int &number_of_tasks)
{
   delete[] user_task[number-1];
   for(int i=number-1;i<number_of_tasks-1;i++)
   {
       user_task[ i ] = user_task[ i+1 ];
   }
   number_of_tasks-=1;
   return user_task;
}
void menu1(task* t)
{
    change_color_rgb(190, 100, 100);
    printf("title: %s\n", t->title);
    reset_color();
    change_color_rgb(180, 65, 90);
    printf("prior: %d\n", t->priority);
    reset_color();
    change_color_rgb(150, 65, 90);
    printf("deadline: %d/%d/%d\n",t->deadline.year,t->deadline.month,t->deadline.day);
    reset_color();
}
void task_addition(task** tasks,int &number_of_tasks)
{
    number_of_tasks+=1;
    tasks[number_of_tasks-1] = new_task();
     for(int i=0;i<number_of_tasks;i++)
     {
        task* priority_check = tasks[i];
        int j = i - 1;
        while (j >= 0 && tasks[j]->priority > priority_check->priority)
        {
            tasks[j + 1] = tasks[j];
            j = j - 1;
        }
        tasks[j + 1] = priority_check;
     }

}
void main_manu_options(task** tasks,int &number_of_tasks)
{
    int answer;
    change_color_rgb(150, 10, 15);
    printf("Please Declare Your Action :");
    reset_color();
    cout<<endl;
    change_color_rgb(15, 200, 190);
    printf("1)viewing task                                 2)task addition                                                3)done");
    reset_color();
    cout<<endl;
    change_color_rgb(150, 100, 15);
    cout<<"Please enter your choice : ";
    //reset_color();

    change_color_rgb(150, 100, 15);
    cin>>answer;
    reset_color();
    cout<<endl;
    if(answer==1)
    {
        int number;
       change_color_rgb(150, 100, 15);
       cout<<"please enter the number of task you want to view : ";
       reset_color();
       change_color_rgb(150, 100, 15);
       cin>>number;
       reset_color();
       cout<<endl;
    task* t = tasks[ number-1 ];
    change_color_rgb(190, 100, 100);
    printf("title: %s", t->title);
    reset_color();
    cout<<endl;
    change_color_rgb(220, 80, 80);
    printf("description : %s",t->desc);
    reset_color();
    cout<<endl;
    change_color_rgb(180, 65, 90);
    printf("priority : %d", t->priority);
    reset_color();
    cout<<endl;
    change_color_rgb(150, 65, 90);
    printf("deadline : %d/%d/%d",t->deadline.year,t->deadline.month,t->deadline.day);
    reset_color();
    cout<<endl;
    change_color_rgb(150, 10, 15);
    printf("Please Declare Your Action :");
    reset_color();
    cout<<endl;
    int choice;
    change_color_rgb(15, 200, 190);
    printf("1)delete task                                                                        2)back to first menu");
    reset_color();
    cout<<endl;
    change_color_rgb(150, 100, 15);
    cout<<"Please Enter Your Choice : "<<endl;
    reset_color();
    change_color_rgb(150, 100, 15);
    cin>>choice;
    reset_color();
    if(choice==1)
 {
    if(number_of_tasks==1)
    {
         delete_task(tasks,number,number_of_tasks);
         change_color_rgb(250, 10, 10);
         printf("NO TASK AVAILABALE");
         reset_color();
         cout<<endl;
        change_color_rgb(15, 200, 190);
         printf("1)Adding A New Task                                                                          2)Done      ");
         reset_color();
         cout<<endl;
         change_color_rgb(150, 100, 15);
         printf("Please Enter Your Choice:");
         reset_color();
         int option;
         change_color_rgb(150, 10, 15);
         scanf("%d",&option);
         reset_color();
         cout<<endl;
         if(option==1)
            {
            task_addition(tasks,number_of_tasks);
            bubble_sort(tasks,number_of_tasks);
            }
         if(option==2)
            exit(0);
    }
    if(number_of_tasks>1)
         delete_task(tasks,number,number_of_tasks);
  }
    if(choice==2)
  {
      change_color_rgb(100, 10, 100);
printf("                                              WELCOM TO FIRST MENU                                                       ");
reset_color();
cout<<endl;
        for (int i = 0; i < number_of_tasks;i++)
    {
        change_color_rgb(40, 200, 230);
        printf("Task %d\n",i+1);
        reset_color();
        menu1(tasks[i]);
    }
    main_manu_options(tasks,number_of_tasks);
  }
    }
    if(answer==2)
    {
        task_addition(tasks,number_of_tasks);
        bubble_sort(tasks,number_of_tasks);
    }
    if(answer==3)
        exit(0);
    for (int i = 0; i < number_of_tasks;i++)
    {
        change_color_rgb(40, 200, 230);
        printf("Task %d\n",i+1);
        reset_color();
        menu1(tasks[i]);
    }
    main_manu_options(tasks,number_of_tasks);

}
void Action_Declaration(task** user_task,int number,int &number_of_tasks)
{
    int choice;
    change_color_rgb(15, 200, 190);
    printf("1)delete task                                                                  2)back to first menu");
    reset_color();
    cout<<endl;
    change_color_rgb(150, 100, 15);
    cout<<"Please Enter Your Choice : "<<endl;
    cin>>choice;
    reset_color();

    if(choice==1 && number_of_tasks>1)
     delete_task(user_task,number,number_of_tasks);
    if(choice==1 && number_of_tasks<=1)
    {
     delete_task(user_task,number,number_of_tasks);
     change_color_rgb(250, 10, 10);
     printf("NO TASK AVAILABALE");
     reset_color();
         cout<<endl;
          change_color_rgb(15, 200, 190);
         printf("1)Adding A New Task                                                                      2)Done      ");
         reset_color();
         cout<<endl;
         change_color_rgb(150, 100, 15);
         printf("Please Enter Your Choice:");
         reset_color();
         int option;
         change_color_rgb(150, 100, 15);
         scanf("%d",&option);
         reset_color();
         cout<<endl;
         if(option==1)
            {
            task_addition(user_task,number_of_tasks);
            bubble_sort(user_task,number_of_tasks);
            }
         if(option==2)
            exit(0);

    }
    if(choice==2)
  {
      change_color_rgb(100, 10, 100);
      printf("                                       WELCOM TO FIRST MENU                                                       ");
      reset_color();
cout<<endl;
        for (int i = 0; i < number_of_tasks;i++)
    {
        change_color_rgb(40, 200, 230);
        printf("Task %d\n",i+1);
        reset_color();
        menu1(user_task[i]);
    }
    main_manu_options(user_task,number_of_tasks);
  }
}

void menu2(task** tasks,int number,int number_of_tasks)
{
    task* t = tasks[ number-1 ];
    change_color_rgb(10, 100, 100);
    printf("                                             WELCOM TO SECOND MENU                                                       ");
    reset_color();
    cout<<endl;
    change_color_rgb(190, 100, 100);
    printf("title: %s", t->title);
    reset_color();
    cout<<endl;
    change_color_rgb(220, 80, 80);
    printf("description : %s",t->desc);
    reset_color();
    cout<<endl;
    change_color_rgb(180, 65, 90);
     printf("priority : %d", t->priority);
     reset_color();
    cout<<endl;
    printf("deadline : %d/%d/%d",t->deadline.year,t->deadline.month,t->deadline.day);
    reset_color();
    cout<<endl;
    change_color_rgb(150, 10, 15);
    printf("Please Declare Your Action :");
    reset_color();
    cout<<endl;
    Action_Declaration(tasks,number,number_of_tasks);

}


int main()
{
    init_clui();
    int number_of_tasks;
    change_color_rgb(75, 100, 190);
    printf("Please Enter The Number Of Tasks:");
    scanf("%d", &number_of_tasks);
     reset_color();
    task** tasks = new task*[number_of_tasks];

     for (int i = 0; i < number_of_tasks; ++i)
    {
        tasks[i] = new_task();
        task* priority_check = tasks[i];
        int j = i - 1;
        while (j >= 0 && tasks[j]->priority > priority_check->priority)
        {
            tasks[j + 1] = tasks[j];
            j = j - 1;
        }
        tasks[j + 1] = priority_check;
    }
    bubble_sort(tasks,number_of_tasks);

change_color_rgb(100, 10, 100);
printf("                                              WELCOM TO FIRST MENU                                                       ");
reset_color();
cout<<endl;
    for (int i = 0; i < number_of_tasks; ++i)
    {
        change_color_rgb(40, 200, 230);
        printf("Task %d\n",i+1);
        reset_color();
        menu1(tasks[i]);
    }
      main_manu_options(tasks,number_of_tasks);
    for (int i = 0; i < number_of_tasks; ++i)
    {
        delete[] tasks[i]->title;
        delete[] tasks[i]->desc;
        delete tasks[i];
    }

    delete[] tasks;
    quit();
    return 0;
}
