    #include <iostream>
    using namespace std;

    int main (void){

    float real, dolar, conversao;

        printf("Digite o valor do real:");
        scanf("%f", &real);

        printf("Digite o valor do dólar:");
        scanf("%f", &dolar);


        conversao = real / dolar;
        printf("O valor do dólar é %f\n", conversao);

        return 0;
    }