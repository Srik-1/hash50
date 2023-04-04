#include <stdio.h>
#include <stdint.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int simple_encrypt(string key, int len);
int complex_encrypt(string key, int len);
int speller(string key, int len);
uint32_t murmur(const void* key, int len, uint32_t seed);
void multi_mode();

int N = 0;

int main(void)
{
    printf("You can encrypt a sinlge key or multiple keys in one go with the same hash!\n");
    printf("1.Single Key\n");
    printf("2.Multiple Keys\n");
    int p = get_int("Select: ");

    uint32_t seed = 42;

    if (p == 2)
    {
        multi_mode();
        return 1;
    }

    string key = get_string("Key: ");
    int len = strlen(key);



    printf("Choose Hash:\n");
    printf("1. Simple \n");
    printf("2. Complex \n");
    printf("3. Speller \n");
    printf("4. MurMur \n");

    int choice;
    do
    {
        choice = get_int("Select: ");
    }
    while (choice > 4 || choice < 1);

    int range = get_int("Range/Max value(optional, Type 0 to leave it at default): ");
    N = range;

    int final = 0;

    switch(choice)
    {
        case 1:
            final = simple_encrypt(key, len);
            printf("Hashed: \n");
            printf("%i\n", final);
            return 1;
        case 2:
            final = complex_encrypt(key, len);
            printf("Hashed: \n");
            printf("%i\n", final);
            return 1;
        case 3:
            final = speller(key, len);
            printf("Hashed: \n");
            printf("%i\n", final);
            return 1;
        case 4:
            final = murmur(key, len, seed);
            printf("Hashed: \n");
            printf("%i\n", final);
            return 1;
    }

}

int simple_encrypt(string key, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += key[i] * (i + 1);
    }

    if (N != 0)
    {
        return sum % N;
    }
    return sum;
}


int complex_encrypt(string key, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += key[i] * key[i] + key[i];
    }

    if (N != 0)
    {
        return sum % N;
    }
    return sum;
}


int speller(string key, int len)
{
    int n = len;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        index = index  + 33 * toupper(key[i]);
    }

    if (N != 0)
    {
        return index % N;
    }
    return index;
}


uint32_t murmur(const void* key, int len, uint32_t seed) {
  const uint8_t* data = (const uint8_t*)key;
  const int nblocks = len / 4;

  uint32_t h1 = seed;

  const uint32_t c1 = 0xcc9e2d51;
  const uint32_t c2 = 0x1b873593;

  const uint32_t* blocks = (const uint32_t*)(data + nblocks*4);

  for(int i = -nblocks; i; i++) {
    uint32_t k1 = blocks[i];

    k1 *= c1;
    k1 = (k1 << 15) | (k1 >> 17);
    k1 *= c2;

    h1 ^= k1;
    h1 = (h1 << 13) | (h1 >> 19);
    h1 = h1*5+0xe6546b64;
  }

  const uint8_t* tail = (const uint8_t*)(data + nblocks*4);

  uint32_t k1 = 0;

  switch(len & 3) {
  case 3: k1 ^= tail[2] << 16;
  case 2: k1 ^= tail[1] << 8;
  case 1: k1 ^= tail[0];
          k1 *= c1; k1 = (k1 << 15) | (k1 >> 17); k1 *= c2; h1 ^= k1;
  };

  h1 ^= len;

  h1 ^= h1 >> 16;
  h1 *= 0x85ebca6b;
  h1 ^= h1 >> 13;
  h1 *= 0xc2b2ae35;
  h1 ^= h1 >> 16;

  return h1;
}


void multi_mode()
{
    uint32_t seed = 42;

    int n = get_int("How many keys?: \n");

    printf("Choose Hash:\n");
    printf("1. Simple \n");
    printf("2. Complex \n");
    printf("3. Speller \n");
    printf("4. MurMur \n");

    int choice;
    do
    {
        choice = get_int("Select: ");
    }
    while (choice > 4 || choice < 1);

    int range = get_int("Range/Max value(optional, Type 0 to leave it at default): ");
    N = range;

    for (int i = 0; i < n; i++)
    {
        int final = 0;
        string key = get_string("Key: ");
        int len = strlen(key);
        switch(choice)
        {
            case 1:
                final = simple_encrypt(key, len);
                printf("Hashed: \n");
                printf("%i\n", final);
                continue;
            case 2:
                final = complex_encrypt(key, len);
                printf("Hashed: \n");
                printf("%i\n", final);
                continue;
            case 3:
                final = speller(key, len);
                printf("Hashed: \n");
                printf("%i\n", final);
                continue;
            case 4:
                final = murmur(key, len, seed);
                printf("Hashed: \n");
                printf("%i\n", final);
                continue;
        }
    }   
}