//
// Created by destshadow on 04/09/23.
//

#ifndef DECL_FOREST_H
#define DECL_FOREST_H

#ifndef FOREST_MALLOC
#include <malloc.h>
#define FOREST_MALLOC malloc
#endif //FOREST_MALLOC

#ifndef FOREST_ASSERT
#include <assert.h>
#define FOREST_ASSERT assert
#endif //FOREST_ASSERT

#include <stack>

struct Node_{
    int content;
    struct Node_ *next;
};

typedef Node_ Node;

struct Forest_{
    std::stack<Node> stack;
};

typedef Forest_ Forest;

[[maybe_unused]] Node *CreaNodo();
[[maybe_unused]] void VisualizzaNodo (Node*);
[[maybe_unused]] Node *InserisciNodo(Node *, int);
[[maybe_unused]] void StampaNodo(Node *);

[[maybe_unused]] Forest *CreaForesta();
[[maybe_unused]] void AggiungiAlbero(Forest& , Node);
[[maybe_unused]] void StampaForesta(const Forest);


#endif //DECL_FOREST_H
#ifdef IMP_FOREST_H


Node *CreaNodo(){
    Node *a;
    a = (Node *) FOREST_MALLOC(sizeof (Node));
    FOREST_ASSERT(a != nullptr);
    return a;
}

void VisualizzaNodo(Node *a){
    while(a != nullptr){
        std::cout << a->content;
    a = reinterpret_cast<Node *>(a->next);
  }
  std::cout<<"\n";
}

Node *InserisciNodo(Node *list, int value){
    Node *tmp;

    tmp = CreaNodo();
    tmp->content = value;
    tmp->next = list;
    list = tmp;

    return list;
}

void StampaNodo(Node *a){
    while (a != nullptr){
        std::cout << a->content;
        a = a->next;
    }
    std::cout<<"\n";
}

Forest * CreaForesta(){
    Forest *a;
    a = (Forest *) FOREST_MALLOC(sizeof (Forest));
    FOREST_ASSERT(a != nullptr);
    return a;
}

void AggiungiAlbero(Forest& a, Node list){
    a.stack.push(list);
}

template <typename T>
void StampaForesta(const Forest a){
    std::stack<T> tmp = a.stack;
    while (!tmp.empty()){
        std::cout<<tmp.top();
        tmp.pop();
    }
}


#endif //IMP_FOREST_H