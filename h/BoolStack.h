#ifndef ASP_DOMACI_REWORK_BOOLSTACK_H
#define ASP_DOMACI_REWORK_BOOLSTACK_H

/*Bool stack koji pokazuje na prvu slobodnu lokaciju.*/

class BoolStack {
public:
    BoolStack();

    BoolStack& push(bool* cvor);

    bool* pop();

    bool stackEmpty() const;

    ~BoolStack();

private:
    bool** stack, **top;
};


#endif //ASP_DOMACI_REWORK_BOOLSTACK_H
