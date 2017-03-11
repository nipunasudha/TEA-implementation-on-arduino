void encrypt (unsigned int* v, unsigned int* k) {
  unsigned int v0 = v[0], v1 = v[1], sum = 0, i;     /* data from array to variables */
  unsigned int delta = 0x9e3779b9;                   /* delta key schedule constant */
  unsigned int k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3]; /* key from array to variables */
  for (i = 0; i < 32; i++) {                     /* cycle through each bit */
    sum += delta;
    v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
    v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
  }
  v[0] = v0; v[1] = v1;                              /* update v array with encrypted data */
}

void decrypt (unsigned int* v, unsigned int* k) {
  unsigned int v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i;  /* data from array to variables */
  unsigned int delta = 0x9e3779b9;                  /* delta key schedule constant */
  unsigned int k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3]; /* key from array to variables */
  for (i = 0; i < 32; i++) {                     /* cycle through each bit */
    v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
    v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
    sum -= delta;
  }
  v[0] = v0; v[1] = v1;
}
void arrayPrinter(unsigned int* ar, int arSize) { /* a function to print a array neatly on console */
  for (int i = 0; i < arSize; i++)
  {
    Serial.print(ar[i]);
    Serial.print(" ");

  }
  Serial.println("");
}
void setup() { /* run only once */
  unsigned int v[] = {12, 34};
  unsigned int k[] = {1, 2, 3, 4};
  Serial.begin(9600);
  Serial.println("========= WELCOME TO TEA CALCULATOR ========");
  Serial.println("# Original 32bit unsigned int array:");
  arrayPrinter(v, 2);
  Serial.println("# Encryption key unsigned int array:");
  arrayPrinter(k, 4);
  Serial.println("========= ENCRYPTING DATA ========");
  encrypt(v, k);
  Serial.println("# Encrypted 32bit unsigned int array:");
  arrayPrinter(v, 2);

  Serial.println("========= DECRYPTING DATA ========");
  decrypt(v, k);
  Serial.println("# Decrypted 32bit unsigned int array:");
  arrayPrinter(v, 2);

}

void loop() { /* nothing to loop */

}
