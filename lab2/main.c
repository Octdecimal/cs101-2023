#include <stdio.h>
#include <string.h>

typedef struct employee {
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_salary;
} employee_t;

void employee_info(employee_t my_emp) {
    printf("employee_id = %d\nemployee_name = %s\nemployee_age = %d\nemployee_phone = %s\nemplotee_salary = %f", my_emp.em_id, my_emp.em_name, my_emp.em_age, my_emp.em_phone, my_emp.em_salary);

}

int main()
{
    employee_t my_emp;
    my_emp.em_id = 99;
    strcpy(my_emp.em_name, "IU Lee");
    my_emp.em_age = 18;
    strcpy(my_emp.em_phone, "0937123456");
    my_emp.em_salary = 1000.30;
    
    printf("size = %ld\n", sizeof(employee_t));
    employee_info(my_emp);
    return 0;
}
