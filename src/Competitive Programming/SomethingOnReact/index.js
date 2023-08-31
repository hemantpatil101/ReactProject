import Header from "./Header.js";
import  ReactDOM from "react-dom";
import React from "react";


function Footer()
{
    return (
    <div>
    <footer><small>@HemantPatil all rights reserved</small></footer>
    </div>
    )
}
/*function Header()
{
    return (
    <header>
        <nav className="nav">
        <img src="./react-logo.png" className="nav-logo"/>
        <ul className="nav-items">
            <li>HOME</li>
            <li>LEARN REACT</li>
            <li>CONTRIBUTE</li>
        </ul>
        </nav>
    </header>)
}*/
function Fun()
{
     return(
        <div>
            <Header />
           <h1>This is made using function</h1>
           <Footer/> 
        </div>
     )
}


ReactDOM.render(<Fun/>,document.getElementById("root"))