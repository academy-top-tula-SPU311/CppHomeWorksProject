#include <iostream>

void ModsExample();
int ComponentSelect();
int ActionSelect();
void ComlectView(unsigned char complect);


int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned char complect{};
    ComlectView(complect);
    std::cout << "\n\n";

    int component;
    int action;

    int mask;

    while (1)
    {
        component = ComponentSelect();
        std::cout << "\n\n";
        action = ActionSelect();
        std::cout << "\n\n";
        
        if (action == 0) break;

        if (action == 1)
        {
            mask = 1 << (component - 1);
            //complect = complect | mask;
            complect |= mask;
        }

        if (action == 2)
        {
            mask = 1 << (component - 1);
            mask = ~mask;
            complect &= mask;
        }

        ComlectView(complect);
        std::cout << "\n\n";
    }

}



void ModsExample()
{
    int a{ 10 };
    int b{ 100 };
    int c{ 3 };
    int d{ 7 };

    for (int i{ a }; i <= b; i++)
        if (i % d == c)
            std::cout << i << " ";
}

int ComponentSelect()
{
    int select;

    std::cout << "1 Одноядерный процессор / Многоядерный процессор\n";
    std::cout << "2 Отсутствие / Наличие DVD - ROM\n";
    std::cout << "3 Отсутствие / Наличие отдельной сетевой платы\n";
    std::cout << "4 Отсутствие / Наличие отдельной звуковой платы\n";
    std::cout << "5 Отсутствие / Наличие отдельной видеоплаты\n";
    std::cout << "6 Обычный жесткий диск(HDD) / твердотельный(SSD)\n";
    std::cout << "7 Один / два монитора\n";
    std::cout << "8 Проводные / беспроводные клавиатура и мышь\n";

    std::cout << "Ваш выбор: ";
    std::cin >> select;

    return select;
}

int ActionSelect()
{
    int select;
    
    std::cout << "1 Добавить\n";
    std::cout << "2 Удалить\n";
    std::cout << "0 Завершить комплектацию\n";
    std::cout << "Ваш выбор: ";
    std::cin >> select;
    
    return select;
}

void ComlectView(unsigned char complect)
{
    int mask;
    int result;
    for (int i{}; i < 8; i++)
    {
        mask = 1 << i;
        result = complect & mask;
        switch (i)
        {
        case 0:
            std::cout << ((!result) ? "Одноядерный" : "Многоядерный") << " прецессор\n";
            break;
        case 1:
            std::cout << ((!result) ? "Отсутствие" : "Наличие") << " DVD-ROM\n";
            break;
        case 2:
            std::cout << ((!result) ? "Отсутствие" : "Наличие") << " отдельной сетевой платы\n";
            break;
        case 3:
            std::cout << ((!result) ? "Отсутствие" : "Наличие") << " отдельной звуковой платы\n";
            break;
        case 4:
            std::cout << ((!result) ? "Отсутствие" : "Наличие") << " отдельной видеоплаты\n";
            break;
        case 5:
            std::cout << ((!result) ? "Обычный" : "Твердотельный") << " жесткий диск\n";
            break;
        case 6:
            std::cout << ((!result) ? "Один" : "Два") << " монитор\n";
            break;
        case 7:
            std::cout << ((!result) ? "Обычные" : "Беспрводные") << " клавиатура и мышь\n";
            break;
        default:
            break;
        }
    }
}
