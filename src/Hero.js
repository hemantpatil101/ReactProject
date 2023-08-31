import mainimg from "./mainimg.png"
export default function Hero()
{
    return(
        <section className="hero">
            <img src={mainimg} className="heroimage"/>
            <h1 className="heroheader">Online Experiences</h1>
            <p className="herotext">Join unique interactive activities led by one-of-a-kind hosts-all without leaving home.</p>
        </section>
    )
}