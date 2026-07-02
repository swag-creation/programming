#include <QTest>
#include <../class_integer/integer.h>
// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void init();
    void cleanup();
    void test_is_prime();
    void test_nod();
    void test_nok();
    void test_print_devisors();
    void test_constructor();
private :
    integer A;
    integer B;
    integer C;
};

test::test() : A(0), B(0), C(0) {};

test::~test() {}
void test::init() {
    A.set_data(2147483647);
    B.set_data(81);
    C.set_data(-420);
}
void test::cleanup() {
    A.set_data(0);
    B.set_data(0);
    C.set_data(0);
}

void test::test_is_prime() {
    QCOMPARE(C.is_prime(), false);
}
void test::test_nod() {
    QCOMPARE(A.nod(-5), 1);
}
void test::test_nok() {
    QCOMPARE(A.nok(2), 4294967294);
}
void test::test_print_devisors() {
    QCOMPARE(C.print_devisors(), QVector<int>({2, 2, 3, 5, 7}));
}
void test::test_constructor() {
    integer D(17);
    QCOMPARE(D.get_data(), 17);
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
