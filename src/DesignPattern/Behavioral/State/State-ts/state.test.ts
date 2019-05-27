import { Context, OpenState } from "./state";


let context = new Context();
context.setState(OpenState.Instance())

context.exec()
context.exec()
context.exec()