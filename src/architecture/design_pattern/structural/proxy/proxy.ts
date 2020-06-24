interface Subject {
    TouchFile();
};
   
class RealSubject implements Subject {
    TouchFile() {
        console.log("touch File")    
    }
};
   
class SubjectProxy implements  Subject {
    TouchFile() {
       const realSubject = new RealSubject();
       realSubject.TouchFile();
     }
};