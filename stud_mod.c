
void stud_mod(ST **p)
{
    if (*p == NULL)
    {
        printf("No records to modify.\n");
        return;
    }

    char op, ch; // op for menu, ch for confirmation
    printf("\n___________________________________________________\n");
    printf("| Enter which record to search for modification   |\n");
    printf("|                                                 |\n");
    printf("|   R/r : to search by Roll Number                |\n");
    printf("|   N/n : to search by Name                       |\n");
    printf("|   P/p : to search by Percentage                 |\n");
    printf("---------------------------------------------------\n");
    scanf(" %c", &op);

    printf("\nDo you want to modify this record? (Y/y): ");
    scanf(" %c", &ch);
    if (!(ch == 'Y' || ch == 'y'))
    {
        printf("\nModification cancelled by user.\n");
        return;
    }

    ST *temp = *p;
    int roll, found = 0, count = 0;
    char name[20];
    float perc;

    switch (op)
    {
    case 'R':
    case 'r':
        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                printf("\nRecord Found:\n");
                printf("-------------------------------------------------\n");
                printf("| Roll No | Name                 | Percentage   |\n");
                printf("-------------------------------------------------\n");
                printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
                printf("-------------------------------------------------\n");

                printf("\nEnter new name: ");
                scanf("%s", temp->name);
                printf("Enter new percentage: ");
                scanf("%f", &temp->marks);

                printf("\nRecord Updated Successfully:\n");
                printf("-------------------------------------------------\n");
                printf("| Roll No | Name                 | Percentage   |\n");
                printf("-------------------------------------------------\n");
                printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
                printf("-------------------------------------------------\n");
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found)
            printf("\nNo record found with Roll No: %d\n", roll);
        break;

    case 'N':
    case 'n':
        printf("Enter Name to modify: ");
        scanf("%s", name);

        temp = *p;
        ST *matches[50];
        count = 0;
        found = 0;

        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                matches[count++] = temp;
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("\nNo record found with Name: %s\n", name);
            break;
        }

        if (count == 1)
        {
            temp = matches[0];
            printf("\nRecord Found:\n");
            printf("-------------------------------------------------\n");
            printf("| Roll No | Name                 | Percentage   |\n");
            printf("-------------------------------------------------\n");
            printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
            printf("-------------------------------------------------\n");

            printf("\nEnter new name: ");
            scanf("%s", temp->name);
            printf("Enter new percentage: ");
            scanf("%f", &temp->marks);

            printf("\nRecord Updated Successfully:\n");
            printf("-------------------------------------------------\n");
            printf("| Roll No | Name                 | Percentage   |\n");
            printf("-------------------------------------------------\n");
            printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
            printf("-------------------------------------------------\n");
        }
        else
        {
            printf("\nMultiple records found with Name: %s\n", name);
            printf("-------------------------------------------------\n");
            printf("| Roll No | Name                 | Percentage   |\n");
            printf("-------------------------------------------------\n");
            for (int i = 0; i < count; i++)
                printf("| %-7d | %-20s | %-11.2f |\n", matches[i]->roll, matches[i]->name, matches[i]->marks);
            printf("-------------------------------------------------\n");

            printf("\nEnter Roll Number to modify: ");
            scanf("%d", &roll);

            for (int i = 0; i < count; i++)
            {
                if (matches[i]->roll == roll)
                {
                    temp = matches[i];
                    printf("\nEnter new name: ");
                    scanf("%s", temp->name);
                    printf("Enter new percentage: ");
                    scanf("%f", &temp->marks);

                    printf("\nRecord Updated Successfully:\n");
                    printf("-------------------------------------------------\n");
                    printf("| Roll No | Name                 | Percentage   |\n");
                    printf("-------------------------------------------------\n");
                    printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
                    printf("-------------------------------------------------\n");
                    break;
                }
            }
        }
        break;

    case 'P':
    case 'p':
        printf("Enter Percentage to modify: ");
        scanf("%f", &perc);

        temp = *p;
        ST *matchesP[50];
        count = 0;
        found = 0;

        while (temp != NULL)
        {
            if (temp->marks == perc)
            {
                matchesP[count++] = temp;
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("\nNo record found with Percentage: %.2f\n", perc);
            break;
        }

        if (count == 1)
        {
            temp = matchesP[0];
            printf("\nRecord Found:\n");
            printf("-------------------------------------------------\n");
            printf("| Roll No | Name                 | Percentage   |\n");
            printf("-------------------------------------------------\n");
            printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
            printf("-------------------------------------------------\n");

            printf("\nEnter new name: ");
            scanf("%s", temp->name);
            printf("Enter new percentage: ");
            scanf("%f", &temp->marks);

            printf("\nRecord Updated Successfully:\n");
            printf("-------------------------------------------------\n");
            printf("| Roll No | Name                 | Percentage   |\n");
            printf("-------------------------------------------------\n");
            printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
            printf("-------------------------------------------------\n");
        }
        else
        {
            printf("\nMultiple records found with Percentage: %.2f\n", perc);
            printf("-------------------------------------------------\n");
            printf("| Roll No | Name                 | Percentage   |\n");
            printf("-------------------------------------------------\n");
            for (int i = 0; i < count; i++)
                printf("| %-7d | %-20s | %-11.2f |\n", matchesP[i]->roll, matchesP[i]->name, matchesP[i]->marks);
            printf("-------------------------------------------------\n");

            printf("\nEnter Roll Number to modify: ");
            scanf("%d", &roll);

            for (int i = 0; i < count; i++)
            {
                if (matchesP[i]->roll == roll)
                {
                    temp = matchesP[i];
                    printf("\nEnter new name: ");
                    scanf("%s", temp->name);
                    printf("Enter new percentage: ");
                    scanf("%f", &temp->marks);

                    printf("\nRecord Updated Successfully:\n");
                    printf("-------------------------------------------------\n");
                    printf("| Roll No | Name                 | Percentage   |\n");
                    printf("-------------------------------------------------\n");
                    printf("| %-7d | %-20s | %-11.2f |\n", temp->roll, temp->name, temp->marks);
                    printf("-------------------------------------------------\n");
                    break;
                }
            }
        }
        break;

    default:
        printf("Invalid choice!\n");
    }
}

