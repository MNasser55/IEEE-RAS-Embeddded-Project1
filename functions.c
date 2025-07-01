// added by kareem_kotb
void create_customer(Customer customers[], int *count) {
    // بنشيك الأول لو عدد العملاء وصل الحد الأقصى
    int ID;
    if (*count >= MAX_CUSTOMERS) {
        printf("Database full!\n");
        return;
    }

    // بنفضل نطلب ID لحد ما يبقى جديد مش مكرر
    while (1) {

        // بناخد ID من اليوزر باستخدام فانكشن بتضمن إنه صحيح
        ID = safeInputInt("Enter ID: ");

        int exists = 0;
        // بندور هل الـ ID ده موجود قبل كده ولا لأ
        for (int i = 0; i < *count; i++) {
            if (ID == customers[i].id) {
                exists = 1;
                char choice;
                // لو موجود بنسأله عايز يعدل بياناته بدل ما يضيفه تاني؟
                printf("This ID already exists.\nDo you want to edit this customer instead? (Y/N): ");
                scanf(" %c", &choice);
                while ((getchar()) != '\n');  // تنظيف البفر من أي مدخلات زيادة

                if (choice == 'Y' || choice == 'y') {
                    // لو قال اه بنديله فانكشن التعديل ونرجع
                    edit_customer(customers, *count);
                    return;
                } else {
                    // لو قال لأ، بنطلب ID جديد
                    printf("Please enter a different ID.\n");
                    break;
                }
            }
        }
        // لو الـ ID مش مكرر بنخرج من اللوب ونكمل
        if (!exists) break;
    }

    // بنخزن الـ ID اللي ادخله المستخدم
    customers[*count].id = ID;
    printf("Enter Name: ");
    scanf("%s", customers[*count].name);  // بنقرأ الاسم

    printf("Enter Phone: ");
    scanf("%s", customers[*count].phone);  // بنقرأ رقم التليفون

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // تنظيف البفر من أي حاجة بعد scanf

    customers[*count].balance = safeInputFloat("Enter Initial Balance: ");  // بندخل الرصيد

    // لو الرصيد بالسالب بنرفض الإدخال
    if (customers[*count].balance < 0) {
        printf("Balance cannot be negative!\n");
        return;
    }

    // لو كل حاجة تمام بنزود العداد
    (*count)++;
    printf("Customer added successfully.\n");
}


void edit_customer(Customer customers[], int count) {
    // دالة لتعديل بيانات عميل موجود
    int id, found = 0;
    id = safeInputInt("Enter ID to edit: ");
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            // لو لقيناه، بنطلب الاسم الجديد والتليفون
            printf("Enter New Name: ");
            scanf("%s", customers[i].name);
            printf("Enter New Phone: ");
            scanf("%s", customers[i].phone);
            printf("Updated successfully.\n");
            found = 1;
            break;
        }
    }
    // لو ملقيناش الـ ID بنقول للمستخدم
    if (!found) printf("Customer not found!\n");
}

void view_customer(Customer customers[], int count) {
    // دالة لعرض بيانات عميل معين
    int id, found = 0;
    id = safeInputInt("Enter ID to view: ");
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            // لو لقيناه بنطبع البيانات بتاعته
            printf("ID: %d\nName: %s\nPhone: %s\nBalance: %.2f\n",
                   customers[i].id, customers[i].name,
                   customers[i].phone, customers[i].balance);
            found = 1;
            break;
        }
    }
    // لو ملقيناش العميل
    if (!found) printf("Customer not found!\n");
}

void delete_customer(Customer customers[], int *count) {
    // دالة لحذف عميل من الليستة
    int id, found = 0;
    id = safeInputInt("Enter ID to delete: ");
    for (int i = 0; i < *count; i++) {
        if (customers[i].id == id) {
            // لو لقيناه، بنحرك باقي العملاء فوقه علشان نحذف
            for (int j = i; j < (*count) - 1; j++) {
                customers[j] = customers[j + 1];
            }
            // نقلل العداد بعد الحذف
            (*count)--;
            printf("Customer deleted.\n");
            found = 1;
            break;
        }
    }
    // لو ملقيناش العميل
    if (!found) printf("Customer not found!\n");
}
