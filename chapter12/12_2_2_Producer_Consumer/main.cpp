#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <stdio.h>

const int  DataSize   = 1000;
const int  BufferSize = 80;
int        buffer[ BufferSize ];
QSemaphore freeBytes( BufferSize );
QSemaphore usedBytes( 0 );

class Producer : public QThread
{
  public:
    Producer();
    void run();
};

class Consumer : public QThread
{
  public:
    Consumer();
    void run();
};

int main( int argc, char *argv[] )
{
    Producer producer;
    Consumer consumer;

    /*启动生产者和消费者线程*/
    producer.start();
    consumer.start();

    /*等待生产者和消费者各自执行完毕后自动退出*/
    producer.wait();
    consumer.wait();

    return 0;
}

Producer::Producer() {}

void Producer::run()
{
    for ( int i = 0; i < DataSize; i++ )
    {
        freeBytes.acquire();
        buffer[ i % BufferSize ] = ( i % BufferSize );
        usedBytes.release();
    }
}

Consumer::Consumer() {}

void Consumer::run()
{
    for ( int i = 0; i < DataSize; i++ )
    {
        usedBytes.acquire();
        fprintf( stderr, "%d", buffer[ i % BufferSize ] );
        if ( i % 16 == 0 && i != 0 )
        {
            fprintf( stderr, "\n" );
        }
        freeBytes.release();
    }
    fprintf( stderr, "\n" );
}
