float sumaDosNumeros(float numeroUno, float numeroDos)
{
    return numeroUno+numeroDos;
}

float restaDosNumeros(float numeroUno, float numeroDos)
{
    return numeroUno-numeroDos;
}

float multiplicacionDosNumeros(float numeroUno, float numeroDos)
{
    return numeroUno*numeroDos;
}

float divisionDosNumeros(float numeroUno, float numeroDos)
{
    return numeroUno/numeroDos;
}

float factorialNumero(float numeroUno)
{
    float acumulador;

    for(acumulador=1;numeroUno>1;numeroUno--){

            acumulador*=numeroUno;
    }

    return acumulador;
}
