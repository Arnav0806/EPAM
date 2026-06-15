thread prod(producer);
    thread cons(consumer);
    prod.join();
    cons.join();