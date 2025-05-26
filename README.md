# Welcome to the Inverted Index Project 👋

This C++ project implements an **Inverted Index** system, a fundamental data structure for building text search engines. It allows you to process documents (PDFs and simple text files), build an efficient index of the words contained within them, and then perform quick searches to find where these words or phrases appear.

## Features

  * **Multi-Format Processing:** Supports reading and indexing documents in **PDF** format (internally converting them to TXT) and **TXT**.
  * **Text Normalization:** Performs accent removal and converts all text to lowercase, ensuring consistent searching regardless of capitalization or accent variations.
  * **Efficient Indexing:** Utilizes a **Trie (Prefix Tree)** data structure to store words, enabling extremely fast lookups.
  * **Precise Occurrence Location:** For each indexed word, the system stores the exact **page** and **line** where the word was found, facilitating context retrieval.
  * **Word and Phrase Search:** Capable of searching for individual words and checking for the presence of entire phrases within the index.

## How It Works

The project is divided into three main components that work together to create and manage the inverted index:

1.  ### `Documentos` (Reader and Pre-processor)

    This class serves as the interface for input files.

      * **PDF Reading:** If a PDF file is provided, the `Documentos` class uses the `poppler` library to extract text from each page. This extracted text is then saved into a temporary `.txt` file with the same base name for further processing.
      * **Text Pre-processing:** For all text files (original TXT or PDF converted to TXT), the `ProcessarTXT` method removes accents, converts all text to lowercase, and filters out non-alphabetic characters. The result is "clean" and standardized text, saved to `texto_processado.txt`, which is ideal for indexing, ensuring that words like "Árvore," "árvore," and "arvore" are treated as the same.
      * **Reading and Indexing:** The `lerTXT` method then reads the cleaned text line by line and word by word, sending each word to the `Trie` for indexing, along with its location (page and line).

2.  ### `Trie` (Prefix Tree)

    This is the central data structure for word storage.

      * A Trie is a tree where each node represents a letter. By traversing the nodes from the root, you form words.
      * **Insertion:** Each unique word from the document is inserted into the Trie. The path traversed in the tree forms the word, and at the final node of the word, a `ListaEncadeada` (Linked List) is attached.
      * **Search:** The Trie allows for extremely fast searching of words and prefixes. By traversing the tree with the letters of the search query, the system can quickly determine if the word exists in the index.

3.  ### `ListaEncadeada` (Occurrences List)

    Associated with each word in the `Trie` is a `ListaEncadeada`. This list stores the occurrences of the word within the documents.

      * Each element in the `ListaEncadeada` (the `Chave` struct) represents a document (identified by the page number).
      * Attached to each `Chave` is a sub-list (the `Inf` struct) that contains the **line numbers** where the word appears within that document/page.
      * This allows the system, when searching for a word, to return not just if it exists, but also its precise location within the documents.

### Simplified Flow:

1.  **Input:** PDF or TXT file.
2.  **`Documentos`:** Reads the file, converts PDF to TXT, cleans the text (removes accents, converts to lowercase, handles punctuation).
3.  **`Documentos`:** Extracts words from the cleaned text, identifying page and line.
4.  **`Trie`:** Inserts each word. At the end of each word's path, it attaches/updates a `ListaEncadeada`.
5.  **`ListaEncadeada`:** Stores the page and line information for each word occurrence.
6.  **Search:** When searching for a word or phrase in the `Trie`, the system quickly retrieves the corresponding `ListaEncadeada`s and displays the locations.

-----

## Getting Started

To compile and run this project, you'll need a C++ compiler.

  * A C++ compiler (like g++).
  * The **Poppler C++ Development library** (for PDF reading). On Debian/Ubuntu-based systems, you can install it using:
    ```bash
    sudo apt-get install libpoppler-cpp-dev
    ```
    For other operating systems, please refer to the Poppler documentation for installation instructions.

### Compilation

Navigate to the project's root directory in your terminal and compile the C++ source files:

```bash
g++ -o main main.cpp Documentos.cpp Trie.cpp Lista.cpp -I/usr/include/poppler/cpp -lpoppler-cpp -std=c++11
```

  * `-o main`: Specifies the output executable name as `main`.
  * `main.cpp Documentos.cpp Trie.cpp Lista.cpp`: Lists all your `.cpp` source files.
  * `-I/usr/include/poppler/cpp`: Includes the directory for the Poppler C++ library headers. (This path might vary based on your system's installation).
  * `-lpoppler-cpp`: Links with the Poppler C++ library.
  * `-std=c++11`: Ensures compatibility with C++11 features (you can use `c++17` or `c++20` for newer standards if desired).

### Execution

After successful compilation, run the executable by providing the path to the file you wish to index and search:

```bash
./main <path/to/your/file.pdf>
# or
./main <path/to/your/file.txt>
```

The program will process the file, build the index, and then allow you to interact with it to perform searches.

-----

## License

This project is licensed under the [MIT License](https://www.google.com/search?q=LICENSE).

**Copyright (c) 2025 Ryan Pablo Coelho Luiz**

For more details on the terms of use, please refer to the `LICENSE` file in the root of this repository.

-----

## Author

This project was conceived and developed by:

**MonkeyShock**
GitHub: (https://github.com/MonkeyShock)
