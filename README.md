# Bem Vindo ao Projeto de Índice Invertido 👋

Este projeto em C++ implementa um sistema de **Índice Invertido**, uma estrutura de dados fundamental para a construção de motores de busca de texto. Ele permite que você processe documentos (PDFs e arquivos de texto simples), construa um índice eficiente das palavras contidas neles e, em seguida, realize buscas rápidas para encontrar onde essas palavras ou frases aparecem.

## Funcionalidades

  * **Processamento de Múltiplos Formatos:** Suporta a leitura e indexação de documentos em formato **PDF** (convertendo-os internamente para TXT) e **TXT**.
  * **Normalização de Texto:** Realiza a remoção de acentos e a conversão de todo o texto para minúsculas, garantindo uma busca consistente e ignorando variações de capitalização ou acentuação.
  * **Indexação Eficiente:** Utiliza uma estrutura de dados **Trie (Árvore de Prefixo)** para armazenar palavras, permitindo buscas extremamente rápidas.
  * **Localização Precisa de Ocorrências:** Para cada palavra indexada, o sistema armazena a **página** e a **linha** exatas onde a palavra foi encontrada, facilitando a recuperação de contexto.
  * **Busca de Palavras e Frases:** Capacidade de pesquisar palavras individuais e verificar a presença de frases completas no índice.

## Como Funciona

O projeto é dividido em três componentes principais que trabalham em conjunto para criar e gerenciar o índice invertido:

1.  ### `Documentos` (Leitor e Pré-processador)

    Esta classe é a interface com os arquivos de entrada.

      * **Leitura de PDFs:** Se um arquivo PDF é fornecido, a classe `Documentos` usa a biblioteca `poppler` para extrair o texto de cada página. Este texto é então salvo em um arquivo `.txt` temporário para processamento.
      * **Pré-processamento de Texto:** Para todos os arquivos de texto (originais ou convertidos de PDF), o método `ProcessarTXT` remove acentos, converte todo o texto para minúsculas e filtra caracteres não alfabéticos. O resultado é um texto "limpo" e padronizado, pronto para ser indexado.
      * **Leitura e Indexação:** O método `lerTXT` lê o texto limpo linha por linha e palavra por palavra, enviando cada palavra para a `Trie` para indexação, juntamente com sua localização (página e linha).

2.  ### `Trie` (Árvore de Prefixo)

    Esta é a estrutura de dados central para o armazenamento de palavras.

      * Uma Trie é uma árvore onde cada nó representa uma letra. Ao percorrer os nós da raiz, você forma palavras.
      * **Inserção:** Cada palavra única do documento é inserida na Trie. O caminho percorrido na árvore forma a palavra, e no nó final da palavra, é anexada uma `ListaEncadeada`.
      * **Busca:** A Trie permite uma busca extremamente rápida por palavras e prefixos. Ao percorrer a árvore com as letras da palavra-chave, o sistema pode determinar rapidamente se a palavra existe no índice.

3.  ### `ListaEncadeada` (Lista de Ocorrências)

    Associada a cada palavra na `Trie`, existe uma `ListaEncadeada`. Esta lista armazena as ocorrências da palavra nos documentos.

      * Cada elemento na `ListaEncadeada` (estrutura `Chave`) representa um documento (identificado pelo número da página).
      * Anexado a cada `Chave`, há uma sub-lista (estrutura `Inf`) que contém os **números das linhas** onde a palavra aparece naquele documento/página.
      * Isso permite que, ao buscar uma palavra, o sistema retorne não apenas se ela existe, mas também a sua localização precisa dentro dos documentos.

### Fluxo Simplificado:

1.  **Entrada:** Arquivo PDF ou TXT.
2.  **`Documentos`:** Lê o arquivo, converte PDF para TXT, limpa o texto (remove acentos, minúsculas, pontuação).
3.  **`Documentos`:** Extrai palavras do texto limpo, identificando página e linha.
4.  **`Trie`:** Insere cada palavra. No final de cada palavra, anexa/atualiza uma `ListaEncadeada`.
5.  **`ListaEncadeada`:** Armazena as informações de página e linha para cada ocorrência da palavra.
6.  **Busca:** Ao pesquisar uma palavra ou frase na `Trie`, o sistema recupera rapidamente as `ListaEncadeada`s correspondentes e exibe as localizações.

## Como Começar

Para compilar e executar este projeto, você precisará de:

  * Um compilador C++ (como g++).
  * A biblioteca Poppler C++ Development (para leitura de PDFs). Em sistemas baseados em Debian/Ubuntu, você pode instalá-la com:
    ```bash
    sudo apt-get install libpoppler-cpp-dev
    ```
    Para outros sistemas, consulte a documentação do Poppler para a instalação.

### Compilação

Navegue até o diretório raiz do projeto no seu terminal e compile os arquivos C++:

```bash
g++ -o main main.cpp Documentos.cpp Trie.cpp Lista.cpp -I/usr/include/poppler/cpp -lpoppler-cpp -std=c++11
```

  * `-o main`: Define o nome do executável como `main`.
  * `main.cpp Documentos.cpp Trie.cpp Lista.cpp`: Lista todos os seus arquivos `.cpp`.
  * `-I/usr/include/poppler/cpp`: Inclui o diretório de cabeçalhos da biblioteca Poppler C++. (Pode variar dependendo da sua instalação).
  * `-lpoppler-cpp`: Linka com a biblioteca Poppler C++.
  * `-std=c++11`: Garante a compatibilidade com C++11 (ou uma versão mais recente, como `c++17` ou `c++20`).

### Execução

Após a compilação, você pode executar o programa passando o caminho para o arquivo que deseja indexar e pesquisar:

```bash
./main <caminho/para/seu/arquivo.pdf>
# ou
./main <caminho/para/seu/arquivo.txt>
```

O programa irá processar o arquivo e construir o índice. Você poderá então interagir com ele para realizar buscas.

## Licença

Este projeto está licenciado sob a [Licença MIT](https://www.google.com/search?q=LICENSE).

**Copyright (c) 2025 Ryan Pablo Coelho Luiz**

Para mais detalhes sobre os termos de uso, consulte o arquivo `LICENSE` na raiz deste repositório.

## Autor

Este projeto foi idealizado e desenvolvido por:

**Ryan Pablo Coelho Luiz**
GitHub: (https://github.com/MonkeyShock)
