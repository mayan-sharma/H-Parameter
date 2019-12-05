#include <stdio.h>

void tType(int r1, int r2, int r3)
{
  float v1, v2, i1, i2, Req, h11, h12, h21, h22;
  printf("Case 1 - Output port short circuited \nEnter input voltage (v1): ");
  scanf("%f", &v1);
  Req = r1 + ((r2 * r3) / (r2 + r3));
  i1 = v1 / Req;
  i2 = i1 / 2;
  h11 = v1 / i1;
  h21 = i2 / i1;
  printf("\nCase 2 - Input port open circuited \nEnter input voltage (v2): ");
  scanf("%f", &v2);
  Req = r2 + r3;
  v1 = v2 / 2;
  i2 = v2 / Req;
  h12 = v1 / v2;
  h22 = i2 / v2;
  printf("Hybrid parameters: \nh11 = %f \nh12 = %f \nh21 = %f \nh22 = %f \n", h11, h12, h21, h22);
}

void piType(int r1, int r2, int r3)
{
  float v1, v2, i1, i2, Req, h11, h12, h21, h22;
  printf("Case 1 - Output port short circuited \nEnter input voltage (v1): ");
  scanf("%f", &v1);
  Req = (r1 * r2) / (r1 + r2);
  i1 = v1 / Req;
  i2 = i1 * (r1 / (r1 + r2));
  h11 = v1 / i1;
  h21 = i2 / i1;
  printf("\nCase 2 - Input port open circuited \nEnter input voltage (v2): ");
  scanf("%f", &v2);
  Req = ((r1 + r2) * r3) / (r1 + r2 + r3);
  v1 = (v2 * r1) / (r1 + r2);
  i2 = v2 / Req;
  h12 = v1 / v2;
  h22 = i2 / v2;
  printf("Hybrid parameters: \nh11 = %f \nh12 = %f \nh21 = %f \nh22 = %f \n", h11, h12, h21, h22);
}

int main()
{
  int choice;
  float r1, r2, r3;
  while (1)
  {
    printf("\nInput values of R1, R2, R3: ");
    scanf("%f%f%f", &r1, &r2, &r3);
    printf("--- H parameter calculator ---\n Choose a network: \n1.T type \n2.Pi type \n3.Exit \nChoice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      tType(r1, r2, r3);
      break;
    case 2:
      piType(r1, r2, r3);
      break;
    case 3:
      return 0;
    default:
      printf("Invalid choice!");
    }
  }
  return 0;
}