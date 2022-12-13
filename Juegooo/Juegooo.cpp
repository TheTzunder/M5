#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#pragma comment(lib, "winmm")

using namespace std;

// Atributos del enemigo 1
string enemy1Name = "Creeper";
int enemyHP = 100;
bool enemyIsAlive = true;

// Atributos del enemigo 2
string enemy2Name = "Zombie";
int enemyHP2 = 100;
bool enemyIsAlive2 = true;

// Atributos de heroe
string heroName;
int heroHP = 1000;
bool heroIsAlive = true;

// Ataques
int Pajaro = 50;
int Amor = 200;
int veces = 1;
int pocion = 2;

//Atribitos del juego
int seleccionEnemigo;

void Start() {
    cout << "" << enemy1Name << " acaba de aparecer y tiene " << enemyHP << " puntos de vida\n";
    cout << "" << enemy2Name << " acaba de aparecer y tiene " << enemyHP2 << " puntos de vida\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
};

int atacar() {
    // ELEGIR A ENEMIGO
    cout << "Elige el enemigo al que atacar\n";
    int num;
    cin >> num;
    return num;
}

bool herolive() {
    if (heroHP <= 0)
    {
        heroHP = 0;
        heroIsAlive = false;
    }
    return heroIsAlive;
}



int main()
{
    cout << "Elige musica 1 Smash 2 Zelda \n";
    int mus;
    cin >> mus;

    switch (mus)
    {
    case 1:
        PlaySound(TEXT("epic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        break;
    case 2:
        PlaySound(TEXT("musica.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        break;

    default:
        break;
    }

    srand(time(NULL));
    Start();
    while (enemyIsAlive == true && heroIsAlive == true && enemyIsAlive2 == true)
    {
        
        seleccionEnemigo = atacar();
        if (seleccionEnemigo == 1)
        {
            cout << "Has elegido atacar a Creeper\n";
            cout << "Indica que ataque deseas usar\n";
            cout << "[1] Pajaro (50 de danyo)\n";
            cout << "[2] El Amor de Ella (200 de danyo)\n";
            cout << "[3] Pocion (100 vida)\n";
            int ataque;
            cin >> ataque;
            switch (ataque)
            {
            case 1:
                enemyHP = enemyHP - Pajaro;
                cout << "Has usado Pajaro.\n";
                cout << "Pillas a un Pajaro que esta volando tranquilo y se lo lanzas\n";
                cout << "Le has hecho " << Pajaro << " puntos de danyo\n";
                cout << "A " << enemy1Name << " le quedan " << enemyHP << " de vida\n";
                break;

            case 2:
                if (veces <= 0)
                {
                    cout << "El Amor de Ella no se puede usar\n";
                }
                else {
                    veces = veces - 1;
                    enemyHP = enemyHP - Amor;
                    cout << "Has usado El Amor de Ella.\n";
                    cout << "El Amor de Ella es supereficaz y deprime al enemigo\n";
                    cout << "Le has hecho " << Amor << " puntos de danyo\n";
                }
                break;
            case 3:
                if (pocion <= 0)
                {
                    cout << "Pocion no se puede usar\n";
                }
                else {
                    pocion = pocion - 1;
                    heroHP = heroHP + 100;
                    cout << "Has usado Pocion.\n";
                    cout << "Has recuperado " << pocion << "ahora tienes " << heroHP << "de vida \n";

                }
                break;
            default:
                break;
            }

            // ESTADO Creeper
            if (enemyHP <= 0)
            {
                enemyIsAlive = false;
                cout << "Te acabas de cargar al enemigo " << enemy1Name << "\n";
                // ATAQUE Zombie
                int enemyDamage = rand() % 200 + 1;
                heroHP = heroHP - enemyDamage;
                herolive();
                if (herolive() == false)
                {
                    cout << "El enemigo " << enemy2Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                }
            }
            else if (enemyHP2 > 0)
            {
                // DA O RANDOM A H ROE
                int enemyDamage = rand() % 200 + 1;
                heroHP = heroHP - enemyDamage;
                cout << "El enemigo " << enemy1Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                herolive();
                if (herolive() == false)
                {
                    heroHP = 0;
                    heroIsAlive = false;
                    cout << "El enemigo " << enemy2Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";

                }
                else if (heroHP > 0)
                {
                    int enemyDamage = rand() % 200 + 1;
                    heroHP = heroHP - enemyDamage;
                    if (herolive() == false)
                    {
                      cout << "El enemigo " << enemy2Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                    }
                }
            }
        }
        // ATACAR Zombie
        else if (seleccionEnemigo == 2)
        {
            cout << "Has elegido atacar a Zombie\n";
            cout << "Indica que ataque deseas usar\n";
            cout << "[1] Pajaro (50 de danyo)\n";
            cout << "[2] El Amor de Ella (200 de danyo)\n";
            cout << "[3] Pocion (100 vida)\n";
            int ataque;
            cin >> ataque;
            switch (ataque) {
            case 1:
                enemyHP2 = enemyHP2 - Pajaro;
                cout << "Has usado Pajaro.\n";
                cout << "Pillas a un Pajaro que esta volando tranquilo y se lo lanzas\n";
                cout << "Le has hecho " << Pajaro << " puntos de danyo\n";
                cout << "A " << enemy2Name << " le quedan " << enemyHP2 << " de vida\n";
                break;
            case 2:
                if (veces <= 0)
                {
                    cout << "El Amor de Ella no se puede usar\n";
                }
                else {
                    veces = veces - 1;
                    enemyHP2 = enemyHP2 - Amor;
                    cout << "Has usado El Amor de Ella.\n";
                    cout << "El Amor de Ella es supereficaz y deprime al enemigo\n";
                    cout << "Le has hecho " << Amor << " puntos de danyo\n";

                }
                break;
            case 3:
                if (pocion <= 0)
                {
                    cout << "Pocion no se puede usar\n";
                }
                else {
                    pocion = pocion - 1;
                    heroHP = heroHP + 100;
                    cout << "Has usado Pocion.\n";
                    cout << "Has recuperado " << pocion << "ahora tienes " << heroHP << "de vida \n";

                }
                break;
            default:
                break;
            }

            // ESTADO Zombie
            if (enemyHP2 <= 0)
            {
                enemyIsAlive2 = false;
                cout << "Te acabas de cargar al enemigo " << enemy2Name << "\n";

                // ATAQUE Creeper
                int enemyDamage = rand() % 200 + 1;
                heroHP = heroHP - enemyDamage;
                herolive();
                if (herolive()== false)
                {
                    cout << "El enemigo " << enemy1Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                }
            }
            else if (enemyHP2 > 0)
            {
                // DA O RANDOM A H ROE
                int enemyDamage = rand() % 200 + 1;
                heroHP = heroHP - enemyDamage;
                cout << "El enemigo " << enemy2Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                if (herolive()== false)
                {
                    cout << "El enemigo " << enemy1Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";

                }
                else if (heroHP > 0)
                {
                    int enemyDamage = rand() % 200 + 1;
                    heroHP = heroHP - enemyDamage;
                    if (herolive() == false)
                    {
                     cout << "El enemigo " << enemy1Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                    }
                }
            }
        }
    }
    while (enemyIsAlive == false && heroIsAlive == true && enemyIsAlive2 == true)
    {

        if (enemyHP2 > 0)
        {
            cout << "Elige con que ataque atacaras a " << enemy2Name << ".\n";
            cout << "[1] Pajaro (50 de danyo)\n";
            cout << "[2] El Amor de Ella (200 de danyo)\n";
            cout << "[3] Pocion (100 vida)\n";

            int ataque;
            cin >> ataque;
            switch (ataque)
            {
            case 1:
                enemyHP2 = enemyHP2 - Pajaro;
                cout << "Has usado Pajaro.\n";
                cout << "Pillas a un Pajaro que esta volando tranquilo y se lo lanzas\n";
                cout << "Le has hecho " << Pajaro << " puntos de danyo\n";
                cout << "A " << enemy2Name << " le quedan " << enemyHP2 << " de vida\n";
                break;
            case 2:
                if (veces <= 0)
                {
                    cout << "El Amor de Ella no se puede usar\n";
                }
                else {
                    veces = veces - 1;
                    enemyHP2 = enemyHP2 - Amor;
                    cout << "Has usado El Amor de Ella.\n";
                    cout << "El Amor de Ella es supereficaz y deprime al enemigo\n";
                    cout << "Le has hecho " << Amor << " puntos de danyo\n";
                }
                break;
            case 3:
                if (pocion <= 0)
                {
                    cout << "Pocion no se puede usar\n";
                }
                else {
                    pocion = pocion - 1;
                    heroHP = heroHP + 100;
                    cout << "Has usado Pocion.\n";
                    cout << "Has recuperado " << pocion << "ahora tienes " << heroHP << "de vida \n";

                }
                break;
            default:
                break;
            }
            if (enemyHP2 <= 0)
            {
                enemyIsAlive2 = false;
            }
            else if (enemyHP2 >= 0)
            {
                // DA O RANDOM A H ROE
                int enemyDamage = rand() % 200 + 1;
                heroHP = heroHP - enemyDamage;
                herolive();
                if (herolive()== false)
                {
                cout << "El enemigo " << enemy2Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                }
            }
        }
    }

    while (enemyIsAlive == true && heroIsAlive == true && enemyIsAlive2 == false)
    {

        if (enemyHP > 0)
        {
            cout << "Solo queda " << enemy1Name << " con vida.\n";
            cout << "Elige con que ataque atacaras a " << enemy1Name << ".\n";
            cout << "[1] Pajaro (50 de danyo)\n";
            cout << "[2] El Amor de Ella (200 de danyo)\n";
            cout << "[3] Pocion (100 vida)\n";

            int ataque;
            cin >> ataque;
            switch (ataque)
            {
            case 1:
                enemyHP = enemyHP - Pajaro;
                cout << "Has usado Pajaro.\n";
                cout << "Pillas a un Pajaro que esta volando tranquilo y se lo lanzas\n";
                cout << "Le has hecho " << Pajaro << " puntos de danyo\n";
                cout << "A " << enemy1Name << " le quedan " << enemyHP << " de vida\n";
                break;
            case 2:
                if (veces <= 0)
                {
                    cout << "El Amor de Ella no se puede usar\n";
                }
                else {
                    veces = veces - 1;
                    enemyHP = enemyHP - Amor;
                    cout << "Has usado El Amor de Ella.\n";
                    cout << "El Amor de Ella es supereficaz y deprime al enemigo\n";
                    cout << "Le has hecho " << Amor << " puntos de danyo\n";
                }
                break;
            case 3:
                if (pocion <= 0)
                {
                    cout << "Pocion no se puede usar\n";
                }
                else {
                    pocion = pocion - 1;
                    heroHP = heroHP + 100;
                    cout << "Has usado Pocion.\n";
                    cout << "Has recuperado " << pocion << "ahora tienes " << heroHP << "de vida \n";

                }
                break;
            default:
                break;
            }
            if (enemyHP <= 0)
            {
                enemyIsAlive = false;
            }
            else if (enemyHP > 0)
            {
                // DA O RANDOM A H ROE
                int enemyDamage = rand() % 200 + 1;
                heroHP = heroHP - enemyDamage;
                herolive();
                if (herolive() == false)
                {
                    cout << "El enemigo " << enemy1Name << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
                }
                if (enemyIsAlive == false && heroIsAlive == true && enemyIsAlive2 == false)
                {
                    cout << "GG has matado a ambos enemigos.\n";
                }
                else if (enemyIsAlive == true && heroIsAlive == false && enemyIsAlive2 == true)
                {
                    cout << "You Lose.\n";
                }
            }
        }
    }
}