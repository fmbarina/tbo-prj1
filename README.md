# TBO-TSP 

[github](https://github.com/fmbarina/tbo-prj1) | [docs](https://fmbarina.github.io/tbo-prj1)

Travelling Salesman Problem utilizando uma MST (Minimum Spanning Tree), feito para a matéria de Tópicos de Busca e Ordenação, Ufes. Os componentes (TADs/bibliotecas) utilizados em sua na concepção estão documentados online, graças ao uso do [Doxygen](https://www.doxygen.nl) e [doxygen-awesome-css](https://jothepro.github.io/doxygen-awesome-css/).

## Como usar

Para compilar, rode `make`. Será gerado um arquivo `trab1` na raíz do repositório.

Com `trab1`, basta rodar `./trab1 problema.tsp`. O programa irá gerar os arquivos de saída `problema.mst` e `problema.tour` no diretório de execução.

O repositório também inclui um script de teste (quase) automático e alguns arquivos de entrada.

- Os testes podem ser (quase) automaticamente feitos com `make test`. A saída estará em `tests/out/`
- Para adicionar testes, crie um novo arquivo de entrada dentro de `tests/in/`

## Agradecimentos

Obrigado a jothepro por fornecer doxygen-awesome-css (`/docs/misc/LICENSE`), usado na geração da documentação. 