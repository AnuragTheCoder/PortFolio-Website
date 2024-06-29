import s from './AboutTextCard.module.scss';
import { ImPointRight } from 'react-icons/im';

const AboutTextCard = () => {
  return (
    <div className={s.card}>
      <p style={{ textAlign: 'justify' }}>
        Hi Everyone, I am{' '}
        <span className={s.purple}>Anurag Jha </span>
        from <span className={s.purple}> Indian Institute Of Technology, Guwahati</span>
        <br />
        Engineering with expertise in cross-platform development{' '}
        <br />
        using MERN stack.
        <br />
        <br />
        I have a Bachelor's of Technology degree in Biotechnology from IIT Guwahati and
        <br />
        I love to develop web-apps and solve Data Structures and Algorithms in C++.
        <br />
        <br />
        Apart from coding, some other activities that I love to do!
      </p>

      <ul>
        <li className={s.aboutActivity}>
          <ImPointRight /> Playing Games
        </li>
        <li className={s.aboutActivity}>
          <ImPointRight /> Reading
        </li>
        <li className={s.aboutActivity}>
          <ImPointRight /> Travelling
        </li>
      </ul>
    </div>
  );
};

export default AboutTextCard;
