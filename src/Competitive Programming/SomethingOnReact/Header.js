import React from "react";
export default function Header()
{
    return (
    <header>
        <nav className="nav">
        <img src=".\react-logo.png" className="nav-logo"/>
        <ul className="nav-items">
            <li>HOME</li>
            <li>LEARN REACT</li>
            <li>CONTRIBUTE</li>
        </ul>
        </nav>
    </header>);
}

