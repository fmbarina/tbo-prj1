#ifndef COMMON_H_
#define COMMON_H_

/* Tipo de dados capaz de representar os IDs de vertices de um TSP */
#define IDT int

/* Formato de impressao do tipo de dado IDT, usado em funcoes como printf */
#define IDF "%d"

/* Obrigado a https://stackoverflow.com/questions/47346133 */
/* Transforma parametro X em "String", util para valores numericos */
#define STR_(X) #X

/* Garantir que pre-procesador expanda o parametro antes de converter */
#define STR(X) STR_(X)

#endif /* COMMON_H_ */