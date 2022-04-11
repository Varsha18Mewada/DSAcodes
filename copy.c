void postorder(struct bst *p){
    struct Stack s;
    s.tos = -1;
    if(p==NULL){
        printf("Tree is Empty");
        return;
    }
    push(&s,p);
    while(p!=NULL){
       p = pop(&s);
       while(p!=NULL){
            push(&s,p);
            if(p->right!=NULL)
                push(&s,p->right);
            p = p->left;
       }
       p = pop(&s);
       while(p!=NULL){
        if(p->flag == -1){
            p->flag = 1;
            push(&s,p);
            break;
        }
        printf("%d \n" ,p->data);
        p = pop(&s);
       }
    }
}
