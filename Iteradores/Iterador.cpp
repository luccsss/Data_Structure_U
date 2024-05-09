class Iterator {
unsigned int pos;
Node* aux;
public:
Iterator(unsigned int pos, Node* aux): pos(pos), aux(aux) {}
void operator ++() { pos++; aux = aux->next; }
bool operator !=(Iterator x) { return pos != x.pos; }
T operator *() { return aux->elem; }
};
Iterator begin() {
return Iterator(0, first);
}
Iterator end() {
return Iterator(nElem, nullptr);
}
