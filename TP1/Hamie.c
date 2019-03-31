int sumaDosNumeros(int numeroUno, int numeroDos)
{
    return numeroUno+numeroDos;
}

int restaDosNumeros(int numeroUno, int numeroDos)
{
    return numeroUno-numeroDos;
}

int multiplicacionDosNumeros(int numeroUno, int numeroDos)
{
    return numeroUno*numeroDos;
}

float divisionDosNumeros(int numeroUno, int numeroDos)
{
    return (float)numeroUno/numeroDos;
}

double factorialNumero(int numeroUno)
{
   double acumulador;

    for(acumulador=1;numeroUno>1;numeroUno--){

        acumulador*=numeroUno;
    }

    return acumulador;
}
