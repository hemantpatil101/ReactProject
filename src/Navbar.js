import airbnblogo from "./airbnb.svg"
export default function Navbar()
{
    return(
        <nav>
            <img src={airbnblogo} className="navlogo"/>
        </nav>
    )
}