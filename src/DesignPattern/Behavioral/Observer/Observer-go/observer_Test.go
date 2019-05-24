package main

func main() {
	var subject = &Subuject{}

	var obs = &ConcreteObserver{
		subject: subject,
	}

	subject.Attact(obs)

	for i := 0; i < 10; i++ {
		subject.SetState(i)
	}
}
